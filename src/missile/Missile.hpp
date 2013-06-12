/* 
 * File:   Missile.hpp
 * Author: alessio
 *
 */

#ifndef MISSILE_HPP
#define	MISSILE_HPP
#include "../collision/CollisionEntity.hpp"
namespace tbd {
    //Forward declaration
     class MissionManager;
     class Enemy;
     class Drawer;

    /** Base class for missile.
     * The friendly field selects if it is our missile or theirs. 
     */
    class Missile : public CollisionEntity{
    public:
        virtual void Update(double elapsed) = 0;
        /**
         * Was this missile created by the spaceship. Default is false.
         */
        bool friendly=false;
        virtual ~Missile();
        virtual void handleCollision(HitWindow* window, CollisionEntity* coll);
    protected:
        Missile(Drawer* d, MissionManager* mm);
        MissionManager* missionmanager;

    };
}
#endif	/* MISSILE_HPP */

