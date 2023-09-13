#include "Camera.h"
#include "Ray.h"

Camera::Camera()
{
}

Camera::~Camera()
{
}

Ray Camera::GenerateRay(glm::ivec2 coordinate)
{
    //float nearZ = -1.0f, farZ = 1.0f;

    //input to function is coordinates, ranging from 0,0 to max resolution
    //convert that to range of -1 and 1
    /*
    float farZX = coordinate.x / coordinate.x;
    float nearZX = farZX * -1;
    float farZY = coordinate.y / coordinate.y;
    float nearZY = farZY * -1;

    //construct 2 3d points, for near and far point
    glm::vec3 far, near;

    //x and y is from first task, z is -1 for near and 1 for far
    //points must be vec4 with 1 as w component
    glm::vec4 point1, point2; point1.w = 1; point2.w = 1;

    //multiply each coordinate by inverse projection matrix from camera
    //divide everything by w to get it back 1
    glm::mat4 inverseProj = glm::inverse(projMatrix);
    */
    //multiply near point and far point by inverse viewing matrix
    //return ray and workout direction and origin

    Ray ray;
    ray.origin = glm::vec3(glm::vec3(coordinate.x, coordinate.y, 0));
    ray.direction = glm::vec3(glm::vec3(0, 0, -1));

    return ray;
    
}
