/* 
 * File:   MissionStats.hpp
 * Author: alessio
 *
 * Created on 30 giugno 2013, 10.46
 */

#ifndef MISSIONSTATS_HPP
#define	MISSIONSTATS_HPP
namespace tbd {
    /**
     * Simple container class for the statistics of the mission.
     * It is updated and returned by the MissionManager
     */
    class MissionStats {
    public:
        /**
         * Number of enemy destroyed during the level
         */
        int enemydestroyed = 0;
        /**
         * Runtime of the level
         */
        double runtime=0.0;
    };
}
#endif	/* MISSIONSTATS_HPP */

