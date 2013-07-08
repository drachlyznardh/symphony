#ifndef CORE_HPP
#define	CORE_HPP
#include "../collision/CollisionEntity.hpp"
#include "../space/SpaceShipComponent.hpp"
#include <vector>

namespace tbd {
    class SpaceShip;//Forward declaration
    class HitWindow;
    /**
     * The core of a ship: contains information about engines, number of weapons, expansions, ecc...
     */
    class SpaceShipCore : public CollisionEntity, public SpaceShipComponent{
    public:
        /**
         * Simple constructor
         * @param d Entity that draws the core
         */
        SpaceShipCore(Drawer* d);
        /**
         * Tells the core which is the spaceship (called by the spaceship at building time)
         * @param space The spaceship 
         */
        void setSpaceShip(SpaceShip* space);
        /**
         * List of all hardpoints of the core
         */
        std::vector <std::pair<double,double>> hardpoints;        
        /**
         * @return the number of Hit Points of the Core
         */
        virtual int getStartingHP()=0;
        /**
         * @return the speed of the Core
         */
        virtual double getSpeed()=0;
        /**
         * @return the amount of energy produced by the Core
         */
        virtual int getEnergyPool()=0;
        /**
         * @return The number of expansions that you can install on the spaceship
         */
        virtual int getExpansionsNumber()=0;
        /**
         * Updates the status of the Core
         * @param elapsed Number of milliseconds since last frame
         */
        virtual void Update(double elapsed)=0;        
        virtual void handleCollision(HitWindow* window, CollisionEntity* coll)=0;
        /**
         * Engages the Core and prepares it for takeoff
         */
        virtual void engage();
        /**
         * The spaceship that contains the core
         */
        SpaceShip* spaceship;

    };
}

#endif	/* CORE_HPP */

