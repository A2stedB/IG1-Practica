#include "BoxOutline.h"
#include "Mesh.h"
using namespace glm;
BoxOutline::BoxOutline(GLfloat length)
{
	mMesh = Mesh::generateBoxOutline(length);
}

//void BoxOutline::render(const glm::mat4& modelViewMat) const
//{
//	if (mMesh != nullptr)
//	{
//		mat4 aMat = modelViewMat * mModelMat;
//		mShader->use();
//		upload(aMat);
//
//		//glEnable(GL_CULL_FACE);
//		//glCullFace(GL_FRONT);   // Oculta la cara trasera para que los procesos que ocurran ahora solo afecten a la frontal
//
//		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);  // PUNTOS
//		//mMesh->render();
//
//		//glCullFace(GL_BACK);  // Oculta la cara frontal para que los procesos que ocurran ahora solo afecten a la trasera
//
//		//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);  // LINEAS
//		mMesh->render();
//
//
//		/*glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);*/
//		//glDisable(GL_CULL_FACE);
//
//	}
//}
