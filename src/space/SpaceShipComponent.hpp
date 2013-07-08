
#ifndef SPACESHIPCOMPONENT_HPP
#define	SPACESHIPCOMPONENT_HPP

namespace tbd {
    /**
     * SpaceShip Component: simple class, useful to help recognize if
     * an entity is part of a spaceship and if it is alive
     */
    class SpaceShipComponent {
    public:
        /**
         * The hit points of this component
         * @return the number of current hit points
         */
        virtual int getHP();
    protected:
        /**
         * Current hit points of the component
         */
        int HP;

    };
}

#endif	/* SPACESHIPCOMPONENT_HPP */

