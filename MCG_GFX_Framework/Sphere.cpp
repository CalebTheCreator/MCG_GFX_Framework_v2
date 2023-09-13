#include "Sphere.h"
#include "Ray.h"
#include "Camera.h"
#include "Colour.h"

Sphere::Sphere()
{
    colour = glm::vec3(1, 0, 0);
    radius = 50.0f;
}

Sphere::Sphere(Colour _colour, float _radius, glm::vec3 _position)
{
    glm::vec3 red = glm::vec3(1, 0, 0);
    glm::vec3 green = glm::vec3(0, 1, 0);
    glm::vec3 blue = glm::vec3(0, 0, 1);
    

    switch (_colour)
    {
    case Colour::RED:
        colour = red;
        break;

    case Colour::GREEN:
        colour = green;
        break; 
    
    case Colour::BLUE:
        colour = blue;
        break;

    default:
        break;
    }
    
    radius = _radius;
    position = _position;
}

Sphere::Sphere(float _radius, glm::vec3 _position)
{
    radius = _radius;
    position = _position;
}

Sphere::~Sphere()
{
}

glm::vec3 Sphere::ShadePixel(Ray r, glm::vec3 _intersectionPoint)
{
    // This will look a bit like a shader

    // You need the surface normal

    // I suggest you start with a dot product between the normal and the inverse direction of the ray

    glm::vec3 surfaceNorm = glm::normalize(_intersectionPoint - position); //normalizing difference between
                                                                   //intersection point and centre of sphere

    glm::vec3 lightPos = glm::vec3(-0.5, 0, 1.0); //placing the light at a position in the world 
                                                    //(similar to how I did it in OpenGL) 

    float pixelLight = glm::dot(lightPos, surfaceNorm); //get dot product between light
                                                       //and surface normal
                                                       //this will give normalized light

    return pixelLight * colour; //return normalized light multiplied by 
                                //sphere colour (in order to shade the correct colour)
                                //(similar to GLSL lighting of each fragment)
}

bool Sphere::RayIntersection(Ray r/*, glm::vec3& intersectionPoint*/)
{
    // check if ray's origin is inside sphere and decide if this is a hit or not (e.g. just return false)

    // find closest point on the ray to the centre of the sphere
    // (this is basically the value of d in teh equations)

    // trying to find magnitude of: 𝑷−𝒂−((𝑷−𝒂)⋅𝒏)𝒏  <-- this equation willl give us a vector
    // we need to take magnitude of this (taking the magnitude gives us a scalar)
    // that scalar is the value 'd',
    //   which is the distance from the closet point on the line to the centre of the sphere
    // 𝑷 is the centre of the sphere (position)
    // 𝒂 is the origin of the ray (r.origin)
    // 𝒏 is the direction of the ray (r.direction)

    glm::vec3 dist = CalculateDistance(position, r.origin, r.direction);
    float d = glm::length(dist); //scalar value

    // once you have d, compare it with the radius of the sphere:
    // if it's less than or equal to the radius, there is a hit

    if (d <= radius)
    {
        // If we're in here, we know there is a hit
        // Now we need to work out the actual intersection point


        // check if closest point on sphere is in front of camera (return no hit if it's behind) <-- hint, just need the ray


        //𝑥=√(〖𝑟^2−𝑑〗^2 )

        float x = std::sqrt(std::pow(radius, 2) - std::pow(d, 2));

        // If we get here, we know there's a hit

        // Find the actual intersection point using this equation:
        //a + (((P - a) * n) - x) * n

        //a is origin of ray
        //n is direction of ray
        //P is centre of sphere (use the position variable from the base class)
        //d is distance from closest point on ray to centre of sphere

        // This is the distance from the ray's origin to where it intersects with the sphere
        // This info might be useful to output from this function so you can use it when dealingi with multipel objects
        float distToIntersect = (glm::dot((position - r.origin), r.direction) - x);

        // put actual intersection point into the intersectionPoint variable and return if there was a hit :)
        intersectionPoint = r.origin + distToIntersect * r.direction;



        return true;
    }

    // There is no hit
    return false;
}

float Sphere::GetRadius()
{
    return radius;
}

glm::vec3 Sphere::GetNormal(glm::vec3& sphereCentre, glm::vec3& samplePoint)
{

    return glm::vec3();
}

glm::vec3 Sphere::CalculateDistance(glm::vec3 _P, glm::vec3 _a, glm::vec3 _n)
{
    // trying to find magnitude of: 𝑷−𝒂−((𝑷−𝒂)⋅𝒏)𝒏

    glm::vec3 distance = _P - _a - (glm::dot((_P - _a), _n)) * _n;

    return distance;
}


