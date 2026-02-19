#include "Scene3.h"
#include "Cube.h"
#include "RGBCube.h"
void Scene3::init()
{
    setGL();
    //gObjects.push_back(new RGBAxes(400.0));
    //gObjects.push_back(new Cube(200));
    gObjects.push_back(new RGBCube(200));
}