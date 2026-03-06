#include "EntityWithTexture.h"

class Grass :public EntityWithTexture
{
public:
	Grass(GLdouble length, const char* texture, GLubyte alpha = 255);
	~Grass() override;
	void render(const glm::mat4& modelViewMat) const override;
};

