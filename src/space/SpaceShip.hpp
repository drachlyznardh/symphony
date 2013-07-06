/* 
 * File:   SpaceShip.hpp
 * Author: alessio
 *
 */

#ifndef SPACESHIP_HPP
#define	SPACESHIP_HPP

#include "../collision/CollisionEntity.hpp"
namespace tbd {
    class MissionManager; //Forward declaration
/**
 * Example of a DrawableEntity.
 * In time it might actually become a real Spaceship!!!
 */
    class SpaceShip : public CollisionEntity {
    public:
        SpaceShip(Drawer* d,MissionManager* mm);
        SpaceShip(Drawer* d);
        void Update(double elapsed);
        double speed=0.4;
        bool isAlive();
        void handleCollision(HitWindow* window,CollisionEntity* other);
        void setMissionManager(MissionManager* mm);
    private:        
        MissionManager* missionmanager;
        const double period=0.2;
        double waitingtime=0.0;
        bool alive=true;
    };
}

#endif	/* SPACESHIP_HPP */

