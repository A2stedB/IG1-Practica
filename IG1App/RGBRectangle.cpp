#include "RGBRectangle.h"
using namespace glm;
RGBRectangle::RGBRectangle(GLdouble w, GLdouble h) 
{
    mMesh = Mesh::generateRGBRectangle(w, h);
}

void RGBRectangle::render(const glm::mat4& modelViewMat) const
{
    if (mMesh != nullptr)
    {
        mat4 aMat = modelViewMat * mModelMat;
        mShader->use();
        upload(aMat);
        glEnable(GL_CULL_FACE);
        //glEnable(GL_POLYGON_OFFSET_LINE);
        glCullFace(GL_FRONT);
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        mMesh->render();


        // Cmabiar el estado de la maquina de estado
        glCullFace(GL_BACK);
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); // Wireframe
        mMesh->render();

        // Resetear estado?
        glDisable(GL_CULL_FACE);
    }
}

void RGBRectangle::update() 
{
    GLdouble increment = 1.0;

}

