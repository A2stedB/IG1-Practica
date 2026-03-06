#include "Star3D.h"
#include "Texture.h"

using namespace glm;
Star3D::Star3D(GLdouble radioExterior, GLuint numPuntas, GLdouble altura, Texture* texture) : EntityWithTexture("texture",texture)
{
	mMesh = Mesh::generateStar3DTexCor(radioExterior, numPuntas, altura);
    mModelMat180X = glm::rotate<float>(mModelMat, glm::pi<float>(), glm::vec3(1, 0, 0));

}

void Star3D::render(const glm::mat4& modelViewMat) const
{
    if (mMesh != nullptr) {
        mat4 aMat = modelViewMat * mModelMat;
        mat4 aMat180X = modelViewMat * mModelMat180X;
        mTexture->bind();
        mShader->setUniform("modulate", mModulate);
        upload(aMat);

        mMesh->render();

        upload(aMat180X);

        mShader->setUniform("modulate", mModulate);
        mMesh->render();

        mTexture->unbind();


        


    }
}
