#ifndef MISSIONMANAGER_HPP
#define	MISSIONMANAGER_HPP

#include <vector>
#include <set>
#include "Polycode.h"
#include "mission/MissionStats.hpp"
#include "ConsoleListener.hpp"

namespace tbd {
    //Forward declaration
    class Enemy;
    class Mission;
    class SpaceShip;
    class Missile;
    class Layer;
    class Background;
    class DrawableEntity;
    class CollisionManager;
    class GUI;
    
/**
 * Super important class that should be able to run a single mission, if well defined.
 */
    class MissionManager {
    public:
        /**
         * Simple costructor
         * @param c Polycode Core
         */
        MissionManager(Polycode::Core* c);
        /**
         * Runs the mission, returns true if the spaceship survived.
         * It needs the setSpaceship and setMission to be called before this method!!
         */
        bool run();
        /**
         * Adds an enemy to the world
         * @param enemy the Enemy to add
         */
        void add(Enemy* enemy);
        /**
         * Adds a missile to the world
         * @param missile the Missile to add
         */
        void add(Missile* missile);
        /**
         * Removes an enemy from the world
         * @param enemy
         */
        void remove(Enemy* enemy);
        /**
         * Removes a missile from the world
         * @param missile
         */
        void remove(Missile* missile);
        /**
         * Sets the spaceship that will have to solve the mission
         * @param s
         */
        void setSpaceship(SpaceShip* s);
        /**
         * Sets the mission to run
         */
        void setMission(Mission* m);
        /**
         * Returns the number of live enemies in the world
         */
        int getNumberOfEnemies();
        /**
         * Contains all the stats of the mission
         */
        MissionStats stats;
        /**
         * Pointer to the spaceship
         */
        SpaceShip* spaceship;
        /**
         * GUI to show while running
         */
        GUI* gui;
        /**
         * Listens for commands on the console
         */
        ConsoleListener cl;
    private:
        Mission* mission;
        Polycode::Core* core;
        Layer* BackgroundLayer;
        Layer* Ships;
        Layer* Missiles;
        Background* background;
        std::vector<Enemy*> enemies;
        std::vector<Missile*> missiles;
        std::set<DrawableEntity*> toDelete;
        CollisionManager* collisionmanager;
        void cleanup();
    };
}
#endif	/* MISSIONMANAGER_HPP */

