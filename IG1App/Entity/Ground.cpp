#include "Ground.h"
using namespace glm;

Ground::Ground(GLdouble length, const char* texture) : EntityWithTexture(texture)
{
    mMesh = Mesh::generateRectangleTextCor(length, length);
    mModelMat = glm::rotate<float>(glm::mat4(1.0f), glm::pi<float>() / 2, glm::vec3(1, 0, 0));
}

Ground::Ground(GLdouble length, Texture* texture) : EntityWithTexture(texture)
{
    mMesh = Mesh::generateRectangleTextCor(length, length);
    mModelMat = glm::rotate<float>(glm::mat4(1.0f), glm::pi<float>() / 2, glm::vec3(1, 0, 0));
}
