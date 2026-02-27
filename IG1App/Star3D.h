#include "EntityWithTexture.h"
#include "Texture.h"

class Star3D : public EntityWithTexture
{
public:
	Star3D(GLdouble radioExterior, GLuint numPuntas, GLdouble altura, Texture * texture);
	void render(const glm::mat4& modelViewMat) const override;

private:

	glm::mat4 mModelMat180X;
};

