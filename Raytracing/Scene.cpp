#include "Scene.h"

void Scene::add_object(Surface* object) {
	objects.push_back(object);
}

glm::vec3 Scene::trace(Ray ray, float t_min, float t_max) {
	float min_t = -1;

	//find the closest intersection's t.
	for (int i = 0; i < objects.size(); i++) { 
		float temp_t = objects[i]->intersect(ray, t_min, t_max);
		if ( temp_t != -1 && (min_t == -1 || temp_t < min_t)) {
			min_t = temp_t;
		}
	}

	if ( min_t != -1 ) { 
		glm::vec3 intersection_point = ray.origin + ray.dir * min_t; //the closest intersection point.
		return glm::vec3(1.0f, 1.0f, 1.0f); //WHITE
	}else{}

	return glm::vec3(0.0f, 0.0f, 0.0f); //BLACK
}