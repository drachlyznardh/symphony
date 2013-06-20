/* 
 * File:   WarsFirstMission.hpp
 * Author: alessio
 *
 * Created on 5 giugno 2013, 14.28
 */

#ifndef WARSFIRSTMISSION_HPP
#define	WARSFIRSTMISSION_HPP
#include "Mission.hpp"
namespace tbd {
    class Background;
/** My first mission, 30 seconds long.
 * Creates a number of enemies.
 *
 */
    class WarsFirstMission : public Mission {
    public:
        void Update(double elapsed);

        bool completed();

        Background* getBackground(Layer* l);
        WarsFirstMission(MissionManager* mm);
        double period=1.0;
    private:
        double totalTime;
        double wait;
    };

}
#endif	/* WARSFIRSTMISSION_HPP */

