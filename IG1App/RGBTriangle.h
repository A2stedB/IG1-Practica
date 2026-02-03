#pragma once
#include "Entity.h"
#include "Mesh.h"
class RGBTriangle : public EntityWithColors
{
    public:
        RGBTriangle(GLdouble);
        void update() override;
};
