#ifndef STRAIGHTCANNON_HPP
#define	STRAIGHTCANNON_HPP

#include "Weapon.hpp"
namespace tbd {
/**
*  Straightcannon: shoots straight according to the orientation of the spaceship
 */
    class StraightCannon : public Weapon {
    public:
        StraightCannon();
        int getEnergy();
        void Update(double elapsed);
        void handleCollision(HitWindow* window, CollisionEntity* other);
        int getStartingHP();
        void engage();
    private:
        double period=0.2;
        double waitingtime=0.0;
        
    };
}
#endif	/* STRAIGHTCANNON_HPP */

