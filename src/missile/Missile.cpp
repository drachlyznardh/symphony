/* 
 * File:   Missile.cpp
 * Author: alessio
 * 
 */

#include "Missile.hpp"
#include "../enemy/Enemy.hpp"
#include "../space/SpaceShip.hpp"
#include "../MissionManager.hpp"
#include "../graphics/Drawer.hpp"
#include <iostream>
using namespace tbd;

tbd::Missile::Missile(Drawer* d, MissionManager* mm): CollisionEntity(d),missionmanager(mm){
    
}
Missile::~Missile(){
    
}
void Missile::handleCollision(HitWindow* window,CollisionEntity* coll){
     if (friendly) {
        if (dynamic_cast<Enemy*> (coll)) {
            missionmanager->remove(this);
        }
    } else {
        if (dynamic_cast<SpaceShip*> (coll)) {
            missionmanager->remove(this);
        }

    }
}