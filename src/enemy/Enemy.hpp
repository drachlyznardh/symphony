/* 
 * File:   enemy.hpp
 * Author: alessio
 *
 */

#ifndef ENEMY_HPP
#define	ENEMY_HPP
#include "../collision/CollisionEntity.hpp"
namespace tbd {
    //Forward declaration
    class MissionManager; 
    class Drawer;
    /**
     * Base class for all enemies
     */
    class Enemy : public CollisionEntity {
    public:
        virtual void Update(double elapsed)=0;
    protected:
        Enemy(Drawer* d,MissionManager* mm);
        MissionManager* missionmanager;
    };
}

#endif	/* ENEMY_HPP */

