#include "Object.h"
#include "Ray.h"


Object::Object()
{

}

Object::~Object()
{
}

glm::vec3 Object::GetPosition()
{
    return position;
}

glm::vec3 Object::ShadePixel(Ray r, glm::vec3 _IntersectionPoint)
{
    return glm::vec3(1, 0, 0);
}

glm::vec3 Object::CalculateDistance(glm::vec3 P, glm::vec3 a, glm::vec3 n)
{

    return glm::vec3();
}

/*
glm::vec3 Object::ClosestPoint(Ray* _ray, const glm::vec3 _QueryPoint)
{
    //x = ((P-a)*n)n
    glm::vec3 x = ((_QueryPoint)*_ray->GetDirection());

    return x;
}
*/