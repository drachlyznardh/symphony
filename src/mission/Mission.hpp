/* 
 * File:   Mission.hpp
 * Author: alessio
 *
 */

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
        void setMissionManager(MissionManager* mm);
    protected:
        Mission();
        MissionManager* missionmanager;
    };
}

#endif	/* MISSION_HPP */

