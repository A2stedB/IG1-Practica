#include "Scene2.h"
#include "RGBTriangle.h"
#include "RGBRectangle.h"
#include "RegularPolygon.h"
#include <glm/gtc/constants.hpp>

void Scene2::init() {
    setGL();
    gObjects.push_back(new RGBAxes(400.0));
    GLdouble radius = 200;
    RegularPolygon* circle = new RegularPolygon(360, radius);
    circle->setColor(1, 0, 1, 1);
    gObjects.push_back(circle);

    GLdouble width = 2*(radius * glm::cos(glm::quarter_pi<GLdouble>())); //LMAO
    gObjects.push_back(new RGBRectangle(width,width));
    gObjects.push_back(new RGBTriangle(radius/2));
}
