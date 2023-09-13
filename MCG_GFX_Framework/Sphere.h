#pragma once
#include "GLM/glm.hpp"
#include "Object.h"

class Sphere : public Object
{
public:
	Sphere();
	Sphere(enum Colour _colour, float _radius, glm::vec3 _position);
	Sphere(float _radius, glm::vec3 _position);
	~Sphere();
	glm::vec3 ShadePixel(Ray r, glm::vec3 _intersectionPoint);
	bool RayIntersection(Ray r/*, glm::vec3& intersectionPoint*/);

	float GetRadius();
	void SetRadius(float value) { radius = value; }
	glm::vec3 GetNormal(glm::vec3& sphereCentre, glm::vec3& samplePoint);

	glm::vec3 CalculateDistance(glm::vec3 _P, glm::vec3 _a, glm::vec3 _n);

	void SetColour(float R, float G, float B) { colour = glm::vec3(R, G, B); }

private:
	glm::vec3 colour;
	float radius;
};

