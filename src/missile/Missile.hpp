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
        /**
         * Updates the position of the missile
         * @param elapsed Milliseconds since last round
         */
        virtual void Update(double elapsed) = 0;
        /**
         * Was this missile created by the spaceship. Default is false.
         */
        bool friendly=false;        
        virtual ~Missile();
        virtual void handleCollision(HitWindow* window, CollisionEntity* coll);
    protected:
        /**
         * Constructor of the Missile
         * @param d The paired Drawer class
         * @param mm The missionmanager that contains this missile
         */
        Missile(Drawer* d, MissionManager* mm);
        /**
         * Pointer to the current missionmanager
         */
        MissionManager* missionmanager;

    };
}
#endif	/* MISSILE_HPP */

