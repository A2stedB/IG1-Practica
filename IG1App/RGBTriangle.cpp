#include "RGBTriangle.h"

RGBTriangle::RGBTriangle(GLdouble radius):EntityWithColors()
{
    mMesh = Mesh::generateRegularPolygon(3,radius);
    mMesh->mPrimitive = GL_TRIANGLES;
    mMesh->vColors.emplace_back(1, 0, 0, 1);
    mMesh->vColors.emplace_back(0, 1, 0, 1);
    mMesh->vColors.emplace_back(0, 0, 1, 1);
}
