#include <iostream>
#include <cmath>
#include <memory>
#include <thread>
#include <mutex>
#include <vector>

#include "MCG_GFX_Lib.h"

#include "Classes.h"

int main( int argc, char *argv[] )
{
	// Variable for storing window dimensions
	glm::ivec2 windowSize( 630, 480 );

	// Call MCG::Init to initialise and create your window
	// Tell it what size you want the window to be
	if( !MCG::Init( windowSize ) )
	{
		// We must check if something went wrong
		// (this is very unlikely)
		return -1;
	}

	// Sets every pixel to the same colour
	// parameters are RGB, numbers are from 0 to 1
	MCG::SetBackground( glm::vec3(0,0,0) );

	// Preparing a position to draw a pixel
	glm::ivec2 pixelPosition = windowSize / 2;

	// Preparing a colour to draw
	// Colours are RGB, each value ranges between 0 and 1
	glm::vec3 pixelColour( 1, 0, 0 );


	// Draws a single pixel at the specified coordinates in the specified colour!
	//MCG::DrawPixel( pixelPosition, pixelColour );
	//std::cout << "Position of pixel is: " << pixelPosition.x << ", " << pixelPosition.y << std::endl;

	// Do any other DrawPixel calls here
	// ...

	// Displays drawing to screen and holds until user closes window
	// You must call this after all your drawing calls
	// Program will exit after this line
	//return MCG::ShowAndHold();





	// Advanced access - comment out the above DrawPixel and MCG::ShowAndHold lines, then uncomment the following:
	
	
	// Variable to keep track of time
	float timer = 0.0f;
	//Caleb - Code
	Camera* camera = new Camera();
	RayTracer* raytracer = new RayTracer();

	Sphere* mySphere = new Sphere(100.0f, glm::vec3(220.0f, 360.0f, -200.0f));
	mySphere->SetColour(1, 0, 0); //red
	raytracer->AddObject(mySphere);

	Sphere* mySphere2 = new Sphere(100.0f, glm::vec3(418.0f, 360.0f, -200.0f));
	mySphere2->SetColour(0, 1, 0); //green
	raytracer->AddObject(mySphere2);

	Sphere* mySphere3 = new Sphere(100.0f, glm::vec3(320.0f, 200.0f, -200.0f));
	mySphere3->SetColour(0, 0, 1); //blue
	raytracer->AddObject(mySphere3);

	for (unsigned int a = 0; a < 1000; ++a)
	{

		Sphere* tempSphere = new Sphere(50.0f, glm::vec3(windowSize.x - ((float)a/2), 200.0f, -200.0f));
		tempSphere->SetColour(1, 0, 1); //blue
		raytracer->AddObject(tempSphere);
	}

	int loopAmount = 0;
	int averageTime = 0;
	int totalTime = 0;
	

	// This is our game loop
	// It will run until the user presses 'escape' or closes the window
	while( MCG::ProcessFrame() )
	{
		loopAmount++;
		//get time
		std::chrono::steady_clock::time_point time1 = std::chrono::high_resolution_clock::now();
		

		// Set every pixel to the same colour
		MCG::SetBackground( glm::vec3(0,0,0) );

		// Change our pixel's X coordinate according to time
		//pixelPosition.x = (windowSize.x / 2) + (int)(sin(timer) * 100.0f);
		// Update our time variable
		//timer += 1.0f / 60.0f;

		// Draw the pixel to the screen
		//MCG::DrawPixel( pixelPosition, pixelColour );

		//Caleb - Code
		
		std::vector<std::thread*> threads;
		int amountOfThreads = 128;
		//int partitions = windowSize.x / amountOfThreads;

		for (int i = 0; i < amountOfThreads; i++)
		{
				threads.push_back( new std::thread(ScreenSplitter::SplitScreen, i, amountOfThreads, windowSize, camera, raytracer));
		}

		for (int j = 0; j < threads.size(); j++)
		{
			threads.at(j)->join();
			delete threads.at(j);
		}

		//Get time
		std::chrono::steady_clock::time_point time2 = std::chrono::high_resolution_clock::now();

		//100 miliseconds = 1 second
		std::chrono::milliseconds milsec = std::chrono::duration_cast<std::chrono::milliseconds>(time2 - time1);


		std::cout << "Time taken: " << milsec.count() << std::endl;

		//calculate average time taken to plot on graph
		totalTime += milsec.count();
		averageTime = totalTime / loopAmount;
		std::cout << "Average time: " << averageTime << std::endl;

	}

	

	delete camera;
	delete raytracer;

	return 0;
}
