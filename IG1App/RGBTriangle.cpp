#include "RGBTriangle.h"
#include <iostream>
//#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
RGBTriangle::RGBTriangle(GLdouble radius):EntityWithColors()
{
    mMesh = Mesh::generateRegularPolygon(3,radius);
    mMesh->mPrimitive = GL_TRIANGLES;
    mMesh->vColors.emplace_back(1, 0, 0, 1);
    mMesh->vColors.emplace_back(0, 1, 0, 1);
    mMesh->vColors.emplace_back(0, 0, 1, 1);
}

void RGBTriangle::update()
{
    //glm::rotate(glm::mat4 const& m, float angle, glm::vec3 const& axis);
    mModelMat = glm::translate<float>(mModelMat, glm::vec3(cos(-1), sin(-1), 0));
    mModelMat = glm::rotate<float>(mModelMat,glm::radians(1.0f),glm::vec3(0.0f,0.0f,-1.0f));
    std::cout << "ROTATING" << std::endl;
}
