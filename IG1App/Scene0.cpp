#include "Scene0.h"
void Scene0::init() // ESCENA
{
    setGL(); // OpenGL settings
    gObjects.push_back(new RGBAxes(400.0));
}