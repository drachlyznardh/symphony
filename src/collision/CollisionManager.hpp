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
        /**
         * Simple constructor
         */
        CollisionManager();
        /**
         * Adds a new entity to the manager
         * @param co The entity to be added
         */
        void add(CollisionEntity* co);
        /**
         * Removes an entity from the manager
         * @param co The entity to be removed
         */
        void remove(CollisionEntity* co);
        /**
         * Reacts to the collision
         * @param e The event (from Polycode)
         */
        void handleEvent(Polycode::Event* e);
    };
}

#endif	/* COLLISIONMANAGER_HPP */

