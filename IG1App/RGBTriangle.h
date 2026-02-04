#pragma once
#include "Entity.h"
#include "Mesh.h"
class RGBTriangle : public EntityWithColors
{
    protected:
        bool mUpdate = false;
        GLdouble angle = 0;
    public:
        RGBTriangle(GLdouble);
        void update() override;
};
