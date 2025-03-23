#include "Surface.h"
#include "Plane.h"

Plane::Plane(glm::vec3 plane_position, glm::vec3 plane_normal) 
	: plane_position(plane_position), plane_normal(plane_normal) 
{
	plane_distance = -(glm::dot(plane_normal, plane_position));
}

float Plane::intersect(Ray ray, float t_min, float t_max) {
	//assume ray.dir and plane_normal is normalized.
	float dot_product_result = glm::dot(plane_normal, ray.dir);

	//returns -1 if there is no intersection. (when ray and plane is perpendicular.)
	if (dot_product_result == 0.0f) return -1; 

	float t = glm::dot(plane_position - ray.origin, plane_normal) / dot_product_result;
	if (t >= 0.0f) {
		return glm::max(glm::min(t, t_max), t_min);
	}

	return -1;
}
