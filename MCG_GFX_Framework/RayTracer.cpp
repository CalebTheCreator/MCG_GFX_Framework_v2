#include "RayTracer.h"


#include "Sphere.h"
#include "Ray.h"

RayTracer::RayTracer()
{
}

RayTracer::~RayTracer()
{
	for (int i = 0; i < objects.size(); i++)
	{
		delete objects.at(i);
	}
}

glm::vec3 RayTracer::Trace(Ray _ray)
{
	for (int i = 0; i < objects.size(); i++)
	{
		
		bool hit = objects[i]->RayIntersection(_ray);
		glm::vec3 intersectionPoint = objects[i]->GetIntersectionPoint();

		// This will work for one object, but not for more than one
		// Think about what happens if the second object is closer than the first - it will just shade the first
		if ( hit )
		{
			return objects[i]->ShadePixel(_ray, intersectionPoint);
		}
	}

	return glm::vec3(0, 0, 0);
}

void RayTracer::AddObject(Object* _object)
{
	objects.push_back(_object);
}