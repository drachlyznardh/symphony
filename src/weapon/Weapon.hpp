#ifndef WEAPON_HPP
#define	WEAPON_HPP
#include "../collision/CollisionEntity.hpp"
#include "../space/SpaceShipComponent.hpp"

namespace tbd {
    class SpaceShip;
    class HitWindow;
    class Drawer;
/**
 * Weapon base class
 */
    class Weapon : public CollisionEntity, public SpaceShipComponent {
    public:
        /**
         * Constructor of the weapon
         * @param d Drawer of the weapon
         */
        Weapon(Drawer* d);
        /**
         * Set the spaceship in which the weapon is installed (called by the spaceship)
         * @param ship The spaceship that contains the weapon
         */
        void setSpaceShip(SpaceShip* ship);
        /**
         * @return The amount of energy needed by this weapon
         */
        virtual int getEnergy() = 0;
        /**
         * Updates and fire the weapon
         * @param elapsed Milliseconds since last round
         */
        virtual void Update(double elapsed) = 0;        
        virtual void handleCollision(HitWindow* window, CollisionEntity* other)=0;
        /**
         * @return The starting amount of hit points of the spaceship
         */
        virtual int getStartingHP()=0;
        /**
         * Engages the weapon, before takeoff
         */
        virtual void engage();
        /**
         * Pointer to the spaceship that contains the weapon
         */
        SpaceShip* spaceship;
    };

}
#endif	/* WEAPON_HPP */

