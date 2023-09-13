#include <mutex>
#include <thread>
#include <iostream>

#include "Classes.h"

std::mutex _mtx1;

// Write a function that takes parameters which allows it to draw part of the screen
// You can start this without multithreading and test that it works



// Write another function which will be called by a starting thread
// This takes parameters which allows it to figure out how to:
//  1. split up the screen (e.g. how many threads)
//  2. which part of the screen this particular thread will be rendering (e.g. thread ID, like thread 1 out of 10)
// This calls the first function once it knows which part of the screen it needs to render



// The final 'gotcha' - watch out for race conditions around the draw pixel function ;)

void ScreenSplitter::DrawScreenPartition(int xBegin, int yBegin, glm::ivec2 _windowSize, Camera* _camera, RayTracer* _raytracer)
{
	for (int x = xBegin; x <_windowSize.x + xBegin; ++x)
	{
		for (int y = yBegin; y < _windowSize.y + yBegin; ++y)
		{
			glm::ivec2 pixelPosition = glm::ivec2(x, y);	//making the pixel position every pixel on screen
			Ray ray = _camera->GenerateRay(pixelPosition);  //generate rays at every pixel
			glm::vec3 colour = _raytracer->Trace(ray);      //trace colour once there is a hit
			_mtx1.lock();	//lock thread function
			MCG::DrawPixel(pixelPosition, colour);	//draw the screen
			_mtx1.unlock(); //unlock thread function
		}

	}
	
}

void ScreenSplitter::SplitScreen(int threadIndex, int amountOfThreads, glm::ivec2 _windowSize, Camera* _camera, RayTracer* _raytracer)
{
	glm::ivec2 partitionSize = _windowSize;
	partitionSize.x /= amountOfThreads;

	DrawScreenPartition(threadIndex * partitionSize.x, 0, partitionSize, _camera, _raytracer);


}