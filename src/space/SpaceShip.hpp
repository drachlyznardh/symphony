#ifndef SPACESHIP_HPP
#define	SPACESHIP_HPP

#include "../collision/CollisionEntity.hpp"
#include <vector>
namespace tbd {
    class MissionManager; //Forward declaration
    class SpaceShipCore;
    class Weapon;
    class Expansion;
    /**
     * Spaceship class: it contains all the common logic of spaceship
     * You can set the core, add weapons and components and then assemble, to check if everything is ok.
     */
    class SpaceShip: public DrawableEntity{
    public:
        /**
         * Constructor of the spaceship
         */
        SpaceShip();
        /**
         * Moves the spaceship
         * @param elapsed Milliseconds since last round
         */
        void Update(double elapsed);
        /**
         * Is the spaceship still alive?
         */
        bool isAlive();
        /**
         * Sets the missionmanager in which the spaceship will appear
         * @param mm the missionmanager
         */
        void setMissionManager(MissionManager* mm);
        /**
         * Assembles the spaceship and makes it ready for takeoff.
         * Checks if everything is ok
         */
        void assemble();
        /**
         * Sets the core of the spaceship
         * @param core 
         */
        void setCore(SpaceShipCore* core);
        /**
         * Installs a weapon in the spaceship
         * @param weapon The weapon to install
         * @param hardpoint The ID of the hardpoint in which the weapon will be installed
         */
        void setWeapon(Weapon* weapon, int hardpoint);
        /**
         * Adds an expansion to the spaceship
         * @param exp The expansion to add
         */
        void addExpansion(Expansion* exp);
        /**
         * The collision entity that form the spaceship (to be accessed by the missionmanager)
         */
        std::vector<CollisionEntity*> collisions;
        /**
         * The expansions contained by the spaceship
         */
        std::vector<Expansion*> expansions;
        /**
         * Pointer to the core of the spaceship
         */
        SpaceShipCore* core;
        /**
         * The missionmanager of the spaceship
         */
        MissionManager* missionmanager;
    private:
        const double period=0.2;
        double waitingtime=0.0;
        std::vector<Weapon*> weapons;
    };
}

#endif	/* SPACESHIP_HPP */

