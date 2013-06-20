/* 
 * File:   HomingMissile.hpp
 * Author: alessio
 *
 */

#ifndef HOMINGMISSILE_HPP
#define	HOMINGMISSILE_HPP
#include "Missile.hpp"
namespace tbd {
    //Forward declaration
    class MissionManager;
    class Drawer;
    /**
     * An homing missile, will try to move toward the spaceship.
     * Can be destroyed by other missiles
     */
    class HomingMissile : public Missile {
    public:
        void Update(double elapsed);
        HomingMissile(Drawer* d,MissionManager* mm);
         void handleCollision(HitWindow* window,CollisionEntity* coll);
    private:
        double speed=0.3;
        double angspeed=45.0;
        double age=0.0;
    };
}

#endif	/* HOMINGMISSILE_HPP */

