#pragma once
//#include "SingleColorEntity.h"
#include "EntityWithTexture.h"
class Star3D : public EntityWithTexture
{
private:
	GLfloat mSelfAngleDeg{ 0.0 };
public:
	Star3D(GLdouble re, GLuint np, GLdouble h, const char* texture);
	~Star3D() {};
	void render(const glm::mat4& modelViewMat) const override;
	void update() override;
};

