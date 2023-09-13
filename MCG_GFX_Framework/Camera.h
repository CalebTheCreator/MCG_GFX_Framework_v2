#pragma once
#include "GLM/glm.hpp"

#include "Ray.h"

class Camera
{
public:
	Camera();
	~Camera();
	Ray GenerateRay(glm::ivec2 coordinate);
	glm::vec3 position;

public:
	glm::mat4 viewMatrix;
	glm::mat4 projMatrix;
	
};

