#include "Scene3.h"
#include "RGBCube.h"

void
Scene3::init()
{
	setGL(); // OpenGL settings

	gObjects.push_back(new RGBAxes(400.0));
	gObjects.push_back(new RGBCube(100));

	

}

void Scene3::update()
{
	for (Abs_Entity* entity : gObjects)
	{
		entity->update();
	}
}
