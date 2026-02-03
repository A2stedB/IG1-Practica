#pragma once
#include "Entity.h"
class RGBRectangle : public EntityWithColors
{
    public:
        RGBRectangle(GLdouble, GLdouble);
        void render(const glm::mat4&) const override;
};
