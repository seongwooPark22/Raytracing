#pragma once

#include<vector>
#include <glm/glm.hpp>
#include <glm/gtc/constants.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/string_cast.hpp>

#include "Ray.h"
#include "Surface.h"

class Scene
{
private:
	std::vector<Surface*> objects;

public:
	void add_object(Surface* object);
	glm::vec3 trace(Ray ray, float t_min, float t_max);
};

