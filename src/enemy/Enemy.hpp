#ifndef ENEMY_HPP
#define	ENEMY_HPP
#include "../collision/CollisionEntity.hpp"
namespace tbd {
    class MissionManager; //Forward declaration
    class Drawer;
    /**
     * Base class for all enemies
     */
    class Enemy : public CollisionEntity {
    public:
        /**
         * Moves and updates the Enemy
         * @param elapsed Milliseconds since last round
         */
        virtual void Update(double elapsed)=0;
        /**
         * Is the enemy alive?
         */
        bool alive=true;
    protected:
        /**
         * Constructor of the enemy
         * @param d Drawer of the enemy
         * @param mm MissionManager in which the enemy will appear
         */
        Enemy(Drawer* d,MissionManager* mm);
        /**
         * Pointer to the MissionManager of the Enemy
         */
        MissionManager* missionmanager;
    };
}

#endif	/* ENEMY_HPP */

