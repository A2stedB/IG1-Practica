#include "Entity.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

using namespace glm;

void
Abs_Entity::upload(const mat4& modelViewMat) const
{
	mShader->setUniform("modelView", modelViewMat);
}

Abs_Entity::~Abs_Entity()
{
	delete mMesh;
	mMesh = nullptr;
}

void
Abs_Entity::load()
{
	mMesh->load();
}

void
Abs_Entity::unload()
{
	mMesh->unload();
}

EntityWithColors::EntityWithColors()
{
	mShader = Shader::get("vcolors");
}

void
EntityWithColors::render(mat4 const& modelViewMat) const
{
	if (mMesh != nullptr) {
		mat4 aMat = modelViewMat * mModelMat; // glm matrix multiplication
		mShader->use();
		upload(aMat);
		mMesh->render();
	}
}

RGBAxes::RGBAxes(GLdouble l)
{
	mMesh = Mesh::createRGBAxes(l);
}

SingleColorEntity::SingleColorEntity(glm::vec4 color = {1,1,1,1}):
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
		//mShader->setUniform("color", mColor);
		mShader->use();
		upload(aMat);
		mMesh->render();
	}
}

RegularPolygon::RegularPolygon(GLuint numVertex, GLdouble radius):
	SingleColorEntity()
{
	mMesh = Mesh::generateRegularPolygon(numVertex,radius);
}
