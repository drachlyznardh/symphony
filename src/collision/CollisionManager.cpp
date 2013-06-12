/* 
 * File:   CollisionManager.cpp
 * Author: alessio
 * 
 */

#include "CollisionManager.hpp"
#include "CollisionEntity.hpp"
#include <iostream>
#include "HitWindow.hpp"
using namespace tbd;
using namespace Polycode;
CollisionManager::CollisionManager() : PhysicsScreen(0.01, 60) {
    setNormalizedCoordinates(true,1.0);
    addEventListener(this, PhysicsScreenEvent::EVENT_NEW_SHAPE_COLLISION);
}

void CollisionManager::add(CollisionEntity* co) {
    for (HitWindow* hw : co->windows) {
        hw->Update();
        addCollisionChild(hw,PhysicsScreenEntity::ENTITY_RECT);
    }
}

void CollisionManager::remove(CollisionEntity* co) {
    for (HitWindow* hw : co->windows) {
        removeChild(hw);
    }
}

void CollisionManager::handleEvent(Polycode::Event* e) {
    PhysicsScreenEvent *pe = (PhysicsScreenEvent*) e;
    switch (pe->getEventCode()) {
        case PhysicsScreenEvent::EVENT_NEW_SHAPE_COLLISION:
            HitWindow* w1=((HitWindow*)pe->entity1);
            CollisionEntity* c1=w1->myobject;
            HitWindow* w2=((HitWindow*)pe->entity2);
            CollisionEntity* c2=w2->myobject;
            c1->handleCollision(w1,c2);
            c2->handleCollision(w2,c1);
    }
}
