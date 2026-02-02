#pragma once
#include "Entity.h"
class SingleColorEntity : public Abs_Entity
{

private:
	glm::vec4 mColor;

public:
	explicit SingleColorEntity(glm::vec4 = { 1,1,1,1 });

	glm::vec4 getColor();
	void setColor(GLuint, GLuint, GLuint, GLuint);
	void render(const glm::mat4& modelViewMat) const override;
};




