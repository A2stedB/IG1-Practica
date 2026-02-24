#pragma once
#include "SingleColorEntity.h"
class BoxOutline : public SingleColorEntity
{
public:
	BoxOutline(GLfloat length);
	~BoxOutline() {};
	//void render(const glm::mat4& modelViewMat) const override;
};

