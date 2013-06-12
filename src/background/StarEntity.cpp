/* 
 * File:   StarEntity.cpp
 * Author: alessio
 * 
 */

#include "StarEntity.hpp"
#include "../Utilities.hpp"
#include "../graphics/Drawer.hpp"
using namespace tbd;
StarEntity::StarEntity(Drawer* d, double px) : DrawableEntity(d){
    x=px;
    y=randomDouble(-0.5,0.5);
    dx=randomDouble(minspeed,maxspeed);
    
}

void StarEntity::Update(double elapsed){
    x=x-dx*elapsed;
}