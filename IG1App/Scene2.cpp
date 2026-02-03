#include "Scene2.h"
#include "RGBTriangle.h"
#include "RGBRectangle.h"
void Scene2::init() {
    setGL();
    gObjects.push_back(new RGBAxes(400.0));
    gObjects.push_back(new RGBTriangle(200));
    gObjects.push_back(new RGBRectangle(400,200));
}
