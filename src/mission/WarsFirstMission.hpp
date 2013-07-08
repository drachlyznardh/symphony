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
        WarsFirstMission();
        /**
         * Controls how often does a new enemy appear
         */
        double period=1.0;
    private:
        double totalTime;
        double wait;
    };

}
#endif	/* WARSFIRSTMISSION_HPP */

