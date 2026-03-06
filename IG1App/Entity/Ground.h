#include "EntityWithTexture.h"

class Ground : public EntityWithTexture
{
public:
    Ground(GLdouble length, const char* texture);
    Ground(GLdouble length, Texture* texture);
};
