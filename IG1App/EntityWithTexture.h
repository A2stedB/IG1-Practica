#include "Entity.h"
#include "Texture.h"
#pragma once
class EntityWithTexture : public Abs_Entity
{
protected:

	Texture* mTexture;
	bool mModulate;
public:

	EntityWithTexture(const char* texture,const char* shader = "texture");
	EntityWithTexture(const char* texture, GLubyte alpha,const char* shader = "texture");
	EntityWithTexture(Texture* texture, GLubyte alpha = 255,const char* shader = "texture");
	EntityWithTexture(GLubyte alpha = 255, const char* shader = "texture");
	~EntityWithTexture();
	void setTexture(Texture* tex);
	virtual void render(const glm::mat4& modelViewMat) const override;

};

