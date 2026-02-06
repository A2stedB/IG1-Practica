#include "Cube.h"
using namespace glm;
Cube::Cube(int length) 
{
    mMesh = Mesh::generateCube(length);
}

void Cube::render(const glm::mat4& modelViewMat) const 
{
    mat4 aMat = modelViewMat * mModelMat;
    mShader->use();
    upload(aMat);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_FRONT);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    mMesh->render();

    glCullFace(GL_BACK);
    glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
    mMesh->render();
    glDisable(GL_CULL_FACE);
}
