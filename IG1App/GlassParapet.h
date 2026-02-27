#pragma once
#include "EntityWithTexture.h"
#include "Texture.h"
class GlassParapet : public EntityWithTexture
{
public:
	GlassParapet(GLdouble length,const char* texture, GLint alpha);
	~GlassParapet() {};
	void render(const glm::mat4& modelViewMat) const override;
};

