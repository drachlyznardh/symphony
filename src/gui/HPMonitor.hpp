#ifndef LABEL_HPP
#define	LABEL_HPP

#include "../DrawableEntity.hpp"
#include <string>

namespace tbd {
    class SpaceShip;
    /**
     * Class that checks the Hit Points of the core and the weapons of the spaceship
     */
    class HPMonitor : public DrawableEntity{
    public:
        /**
         * Constructor
         * @param space Spaceship to monitor
         */
        HPMonitor(SpaceShip* space);
        /**
         * Updates the text of the gui
         * @param elapsed Milliseconds since last round (useless for now)
         */
        void Update(double elapsed);
    private:
        SpaceShip* spaceship;
    };
}
#endif	/* LABEL_HPP */

