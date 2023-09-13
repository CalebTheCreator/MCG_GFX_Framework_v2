#pragma once
#include "GLM/glm.hpp"

#include "Ray.h"

class Object
{
public:
	Object();
	~Object();

	glm::vec3 GetPosition();
	void SetPosition(float x, float y, float z) { position = glm::vec3(x, y, z); }

	virtual glm::vec3 ShadePixel(Ray r, glm::vec3 _IntersectionPoint);

	virtual bool RayIntersection(Ray r) = 0;

	glm::vec3 CalculateDistance(glm::vec3 P, glm::vec3 a, glm::vec3 n);

	glm::vec3 GetIntersectionPoint() { return intersectionPoint; }

protected:
	glm::vec3 position;
	glm::vec3 intersectionPoint;
};

