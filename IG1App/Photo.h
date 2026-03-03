#include "EntityWithTexture.h"

class Photo : public EntityWithTexture
{
public:
    Photo(GLdouble width, GLdouble height, GLubyte alpha = 255);
    ~Photo() override;
    void update() override;
};
