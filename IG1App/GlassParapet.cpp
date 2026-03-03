#include "GlassParapet.h"


GlassParapet::GlassParapet(GLdouble length, const char* textPath) : EntityWithTexture(textPath)
{
	mMesh = Mesh::generateBoxOutlineTexCor(length);
}

GlassParapet::~GlassParapet()
{
}
