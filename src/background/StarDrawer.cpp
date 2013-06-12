/* 
 * File:   StarDrawer.cpp
 * Author: alessio
 * 
 */

#include "StarDrawer.hpp"
#include "PolyScreenShape.h"
#include "../DrawableEntity.hpp"
using namespace Polycode;
tbd::StarDrawer::StarDrawer(double height): Drawer(){
    ScreenShape* shape=new ScreenShape(ScreenShape::SHAPE_CIRCLE,height,height);
    shape->setColor(1.0, 1.0, 0.0, 1.0);
    addChild(shape);
}

void tbd::StarDrawer::Update(){
    setPosition(myEntity->x,myEntity->y);
}
