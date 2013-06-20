/* 
 * File:   WarsSecondEnemy.hpp
 * Author: alessio
 *
 */

#ifndef WARSSECONDENEMY_HPP
#define	WARSSECONDENEMY_HPP
#include "Enemy.hpp"
namespace tbd {
    /**
     * My second enemy. Very slow, it shoots Homing Missiles
     */
    class WarsSecondEnemy : public Enemy {
    public:
        WarsSecondEnemy(MissionManager* mm);
        void Update(double elapsed);
        void handleCollision(HitWindow* window,CollisionEntity* other);
    private:
        const double speed=0.1;
        const double period=2.0;
        double currentwait;
    };
}

#endif	/* WARSSECONDENEMY_HPP */

