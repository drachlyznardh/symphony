/* 
 * File:   DrawableEntity.cpp
 * Author: alessio
 * 
 */

#include "DrawableEntity.hpp"
#include "graphics/Drawer.hpp"
#include "Layer.hpp"
#include <iostream>
using namespace tbd;
DrawableEntity::DrawableEntity(Drawer* drawer) {
    drawer->myEntity = this;
    mydrawer = drawer;
}

void DrawableEntity::removeFromLayer() {
    if (mylayer) {
        mylayer->removeChild(mydrawer);
        mylayer = 0;
    }
}

DrawableEntity::~DrawableEntity(){
    removeFromLayer();
    delete mydrawer;
}

void DrawableEntity::copyPosition(DrawableEntity* other){
    x=other->x;
    y=other->y;
}