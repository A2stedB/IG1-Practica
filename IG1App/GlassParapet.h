#include "EntityWithTexture.h"
#include "Texture.h";
class GlassParapet :
    public EntityWithTexture
{
public:
    GlassParapet(GLdouble length, const char* textPath);
    ~GlassParapet();
};

