/* 
 * File:   CollisionManager.hpp
 * Author: alessio
 *
 */

#ifndef COLLISIONMANAGER_HPP
#define	COLLISIONMANAGER_HPP
#include "Polycode2DPhysics.h"
namespace tbd {
    //Forward declaration
    class CollisionEntity;
/**
 * Class that contains all the collision entities and creates the collision events.
 */
    class CollisionManager :public Polycode::PhysicsScreen{
    public:
        CollisionManager();
        void add(CollisionEntity* co);
        void remove(CollisionEntity* co);
        void handleEvent(Polycode::Event* e);
    };
}

#endif	/* COLLISIONMANAGER_HPP */

