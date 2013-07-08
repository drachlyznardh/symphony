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
        /**
         * Constructor of the Missile
         * @param d The paired Drawer class
         * @param mm The missionmanager that contains this missile
         */
        HomingMissile(Drawer* d,MissionManager* mm);
         void handleCollision(HitWindow* window,CollisionEntity* coll);
    private:
        double speed=0.3;
        double angspeed=45.0;
        double age=0.0;
    };
}

#endif	/* HOMINGMISSILE_HPP */

