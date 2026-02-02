#include "SingleColorEntity.h"
using namespace glm;

SingleColorEntity::SingleColorEntity(glm::vec4 color) :
	mColor(color)
{
	mShader = Shader::get("simple");
}

glm::vec4 SingleColorEntity::getColor()
{
	return mColor;
}

void SingleColorEntity::setColor(GLuint r, GLuint g, GLuint b, GLuint a)
{
	mColor.r = r;
	mColor.g = g;
	mColor.b = b;
	mColor.a = a;
}

void SingleColorEntity::render(const glm::mat4& modelViewMat) const
{
	if (mMesh != nullptr)
	{
		mat4 aMat = modelViewMat * mModelMat; // glm matrix multiplication
		mShader->use();
		mShader->setUniform("color", mColor);
		upload(aMat);
		mMesh->render();
	}
}
