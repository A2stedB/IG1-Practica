#include "BoxOutline.h"
#include "Mesh.h"
using namespace glm;

BoxOutline::BoxOutline(GLfloat length, const char* outside_texture, const char* inside_texture) :EntityWithTexture(outside_texture)
{
	mMesh = Mesh::generateBoxOutlineTexCor(length);
	_inside = new Texture();
	_inside->load(inside_texture);
}

BoxOutline::~BoxOutline()
{
	delete _inside;
}
void BoxOutline::render(const glm::mat4& modelViewMat) const
{

	if (mMesh != nullptr && mShader != nullptr)
	{

		mat4 aMat = modelViewMat * mModelMat;

		mShader->use();
		glEnable(GL_CULL_FACE);
		upload(aMat);
		if (mTexture != nullptr && _inside != nullptr)
		{
			mShader->setUniform("modulate", mModulate);

			glCullFace(GL_BACK);
			_inside->bind();     // detras
			mMesh->render();

			glCullFace(GL_FRONT);
			mTexture->bind();   // delante
			mMesh->render();

			_inside->unbind();
			mTexture->unbind();
		}
		else mMesh->render();

		glDisable(GL_CULL_FACE);
	}
}
