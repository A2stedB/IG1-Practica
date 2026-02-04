#include "RGBTriangle.h"
#include <iostream>
//#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <GL/glew.h>     // OpenGL Extension Wrangler
#include <GLFW/glfw3.h>  // OpenGL Library
#include <glm/glm.hpp>   // OpenGL Mathematics
RGBTriangle::RGBTriangle(GLdouble radius):EntityWithColors()
{
    mMesh = Mesh::generateRegularPolygon(3,radius);
    mMesh->mPrimitive = GL_TRIANGLES;
    mMesh->vColors.emplace_back(1, 0, 0, 1);
    mMesh->vColors.emplace_back(0, 1, 0, 1);
    mMesh->vColors.emplace_back(0, 0, 1, 1);
    mModelMat = glm::translate<float>(mModelMat, glm::vec3(0, -200, 0));
}

void RGBTriangle::update()
{
    angle += 1 %360;
    //angle = glfwGetTime();
    //glm::rotate(glm::mat4 const& m, float angle, glm::vec3 const& axis);
    //mModelMat = glm::translate<float>(mModelMat, glm::vec3(90, 0, 0));
    GLdouble rad = glm::radians(angle);

    mModelMat = glm::mat4(1.0f); //...... AAAAAAAAAAAAAAAAAAAAAAAAAAAA
    // Sabes la posicion de nuevo porque ahora va en funcion del radio
    mModelMat = glm::translate<float>(mModelMat, glm::vec3(200 * cos(rad),200 * sin(rad), 0)); // No deberia ser al reves??
    mModelMat = glm::rotate<float>(mModelMat,rad,glm::vec3(0.0f,0.0f,-1.0f));

    //mModelMat = glm::rotate<float>(mModelMat, glm::radians(1.0f),
    //                               glm::vec3(mModelMat[0][0] * cos(rad) - sin(rad) * mModelMat[0][1],
    //                                         mModelMat[0][0] * sin(rad) + cos(rad) * mModelMat[0][1], 0));
    
    //mModelMat = glm::translate<float>(mModelMat,
    //                                  glm::vec3(mModelMat[0][0] * cos(rad) - sin(rad) * mModelMat[0][1], mModelMat[0][0] * sin(rad) + cos(rad) * mModelMat[0][1], 0));
    //mModelMat = glm::rotate<float>(mModelMat, glm::radians(1.0f), glm::vec3(cos(1), sin(1),0));
    //upload(mModelMat);
    //render(mModelMat);
    //std::cout << "ROTATING" << std::endl;
}
