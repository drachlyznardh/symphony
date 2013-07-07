
#ifndef SIMPLECORE_HPP
#define	SIMPLECORE_HPP
 #include "SpaceShipCore.hpp"
namespace tbd {
    class HitWindow;
    /**
     * A quick example of a SpaceShipCore
     */
    class SimpleCore : public SpaceShipCore{
    public:
        int getStartingHP();
        double getSpeed();
        int getEnergyPool();
        int getExpansionsNumber();
        void Update(double elapsed);
        void handleCollision(HitWindow* window, CollisionEntity* coll);
        void engage();
        SimpleCore();
    private:

    };
}

#endif	/* SIMPLECORE_HPP */

