#include "SimpleSprite.hpp"
#include "../DrawableEntity.hpp"
#include <PolyScreenImage.h>
#include <iostream>

using namespace Polycode;
using namespace std;

tbd::SimpleSprite::SimpleSprite(const std::string& filename, double height): Drawer(){
    ScreenImage* si= new ScreenImage(filename);
    double scale=height/si->getHeight();
    si->setScale(scale,scale);
    si->setPositionMode(ScreenEntity::POSITION_CENTER);
    setHeight(height);
    setWidth(scale*si->getWidth());
    addChild(si);
}
