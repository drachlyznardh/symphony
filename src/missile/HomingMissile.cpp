/* 
 * File:   HomingMissile.cpp
 * Author: alessio
 * 
 */

#include "HomingMissile.hpp"
#include "../Utilities.hpp"
#include "../collision/HitWindow.hpp"
#include "../space/SpaceShip.hpp"
#include "../enemy/Enemy.hpp"
#include "../MissionManager.hpp"
#include "../graphics/Drawer.hpp"
using namespace tbd;

void HomingMissile::Update(double elapsed) {
    age+=elapsed;
    speed=age/3.0;
    //Change angle        
    double angle = getAngle(x, y, missionmanager->spaceship->x, missionmanager->spaceship->y);
    if (angle < rotation)
        angle += 360;
    double da = angle - rotation;
    if (da < 180.0) {
        rotation += std::min(elapsed * this->angspeed, da);
    } else {
        rotation -= std::min(elapsed * this->angspeed, 360 - da);
    }
    rotation = fmod(rotation, 360);
    x += cos(rotation * toRad) * elapsed*speed;
    y += sin(rotation * toRad) * elapsed*speed;
}

HomingMissile::HomingMissile(Drawer* d, MissionManager* mm) : Missile(d, mm) {
    rotation = 180.0;
    windows.push_back(new HitWindow(this, d->getWidth(), d->getHeight()));
}

void HomingMissile::handleCollision(HitWindow* window,CollisionEntity* coll) {
    Missile* m;
    if (m = dynamic_cast<Missile*> (coll)) {
        if(m->friendly==!friendly){
            missionmanager->remove(this);
            missionmanager->remove(m);
        }
    } else {
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
}