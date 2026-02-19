#pragma once
#include "SingleColorEntity.h"
class Cube : public SingleColorEntity
{
    public:
        Cube(int);
        void render(const glm::mat4& modelViewMat) const override;
};
