#ifndef MISSION_HPP
#define	MISSION_HPP
#include "../background/Background.hpp"
#include "../Layer.hpp"
namespace tbd {
    //Forward declaration
    class MissionManager;
    class Background;
    class Layer;
/**
 * Mission interface.
 * 
 */
    class Mission {
    public:
        /**
         * Called at each frame. This function creates enemies and does other cool stuff
         * @param elapsed milliseconds since last frame
         */
        virtual void Update(double elapsed) = 0;
        /**
         * Tells the mission manager if the mission has been successfully completed
         */
        virtual bool completed() = 0;
        /**
         * Instantiates and returns the background of the mission
         */       
        virtual Background* getBackground(Layer* l) = 0;
        /**
         * Sets the missionmanager in which to run this mission
         * @param mm The missionmanager that will run the mission
         */
        void setMissionManager(MissionManager* mm);
    protected:
        /**
         * Constructor of the mission
         */
        Mission();
        /**
         * The missionmanager that will run the mission
         */
        MissionManager* missionmanager;
    };
}

#endif	/* MISSION_HPP */

