#include "Drawer.hpp"
#include "../DrawableEntity.hpp"

tbd::Drawer::Drawer():ScreenEntity() {
   setPositionMode(ScreenEntity::POSITION_CENTER);
}

void tbd::Drawer::Update(){
    Polycode::ScreenEntity::Update();
    setPosition(myEntity->x,myEntity->y);
    setRotation(myEntity->rotation);
}