#include "Scene1.h"
#include "RegularPolygon.h"
void Scene1::init() 
{
    setGL(); // OpenGL settings

    // allocate memory and load resources
    // Lights
    // Textures

    // Graphics objects (entities) of the scene

    gObjects.push_back(new RGBAxes(400.0));
    RegularPolygon* polygon = new RegularPolygon(7, 200);
    polygon->setColor(1, 0, 1, 1);
    gObjects.push_back(polygon);

    RegularPolygon* circle = new RegularPolygon(360, 200);
    circle->setColor(1, 1, 0, 1);
    gObjects.push_back(circle);

    polygon->setColor(1, 0, 1, 1);
}
