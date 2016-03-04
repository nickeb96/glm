
#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>

#include "../glm/glm.hpp"


float k_bounds = 10.0f;


float getRand(float min, float max)
{
    return min + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (max - min)));
}

std::string vecToString(const glm::vec3& v)
{
    return "{" + std::to_string(v.x) + ", " + std::to_string(v.y) + ", " + std::to_string(v.z) + "}";
}

void testDistanceToPlane()
{
    glm::vec3 point(getRand(k_bounds, -k_bounds), getRand(k_bounds, -k_bounds), getRand(k_bounds, -k_bounds));
    
    glm::vec3 pointOnPlane(getRand(k_bounds, -k_bounds), getRand(k_bounds, -k_bounds), getRand(k_bounds, -k_bounds));
    
    glm::vec3 normal = glm::normalize(glm::vec3(getRand(k_bounds, -k_bounds), getRand(k_bounds, -k_bounds), getRand(k_bounds, -k_bounds)));
    
    std::cout << "The distance from point " << vecToString(point)
        << " to plane with normal " << vecToString(normal)
        << " and intersecting " << vecToString(pointOnPlane)
        << " is " << glm::distanceToPlane(point, pointOnPlane, normal)
        << "." << std::endl;
}

void testDistanceToLine()
{
    glm::vec3 point(getRand(k_bounds, -k_bounds), getRand(k_bounds, -k_bounds), getRand(k_bounds, -k_bounds));
    
    glm::vec3 pointOnLine(getRand(k_bounds, -k_bounds), getRand(k_bounds, -k_bounds), getRand(k_bounds, -k_bounds));
    
    glm::vec3 direction = glm::normalize(glm::vec3(getRand(k_bounds, -k_bounds), getRand(k_bounds, -k_bounds), getRand(k_bounds, -k_bounds)));
    
    std::cout << "The distance from point " << vecToString(point)
        << " to line with the direction " << vecToString(direction)
        << " and intersecting " << vecToString(pointOnLine)
        << " is " << glm::distanceToLine(point, pointOnLine, direction)
        << "." << std::endl;
}

int main(int argc, char** argv)
{
    std::cout << "Testing distanceToPlane" << std::endl;
    testDistanceToPlane();
    
    std::cout << std::endl;
    
    std::cout << "Testing distanceToLine" << std::endl;
    testDistanceToLine();
    
    return EXIT_SUCCESS;
}
