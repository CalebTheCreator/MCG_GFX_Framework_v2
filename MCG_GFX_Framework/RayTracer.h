#pragma once
#include "GLM/glm.hpp"
#include <vector>

#include "Ray.h"
#include "Object.h"

class RayTracer
{
public:
	RayTracer();
	~RayTracer();
	glm::vec3 Trace(Ray _ray);
	void AddObject(Object* _object);

private:
	std::vector <Object*> objects;

};

