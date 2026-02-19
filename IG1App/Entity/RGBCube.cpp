#include "RGBCube.h"
using namespace glm;

RGBCube::RGBCube(int length) {
    mMesh = Mesh::generateRGBCube(length);
}

void RGBCube::render(const glm::mat4& modelViewMat) const
{
    if (mMesh != nullptr)
    {
        glEnable(GL_CULL_FACE);
        mat4 aMat = modelViewMat * mModelMat;
        mShader->use();
        upload(aMat);
        glCullFace(GL_FRONT);
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        mMesh->render();

        glCullFace(GL_BACK);
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        mMesh->render();
        //glDisable(GL_CULL_FACE);
    }
}
