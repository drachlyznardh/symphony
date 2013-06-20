/* 
 * File:   MyFirstEnemy.hpp
 * Author: alessio
 *
 */

#ifndef MYFIRSTENEMY_HPP
#define	MYFIRSTENEMY_HPP
#include "Enemy.hpp"
namespace tbd {
    /**
     * My first enemy. It shoots Simple Missiles
     */
    class WarsFirstEnemy : public Enemy {
    public:
        WarsFirstEnemy(MissionManager* mm);
        void Update(double elapsed);
        void handleCollision(HitWindow* window,CollisionEntity* other);
    private:
        const double speed=0.1;
        const double period=1.0;
        double currentwait;
    };
}

#endif	/* MYFIRSTENEMY_HPP */

