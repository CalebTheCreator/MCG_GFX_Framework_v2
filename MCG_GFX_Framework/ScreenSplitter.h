#pragma once

#include "MCG_GFX_Lib.h"
#include <mutex>


namespace ScreenSplitter
{
	void DrawScreenPartition(int xBegin, int yBegin, glm::ivec2 windowSize, class Camera* _camera, class RayTracer* _raytracer);

	void SplitScreen(int threadIndex, int amountOfThreads, glm::ivec2 _windowSize, Camera* _camera, RayTracer* _raytracer);
}