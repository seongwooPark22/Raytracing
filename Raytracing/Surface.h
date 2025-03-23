#pragma once

#include <glm/glm.hpp>
#include "Ray.h"

class Surface
{
public:
	virtual ~Surface() {};
	virtual float intersect(Ray ray, float t_min, float t_max) = 0;
};

