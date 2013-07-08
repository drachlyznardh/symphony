

#ifndef EXPANSION_HPP
#define	EXPANSION_HPP
namespace tbd {
    class SpaceShip; //Forward declaration
    /**
     * Expansion class for expansions such as shields, radar, ecc...
     */
    class Expansion {
    public:
        /**
         * Spaceship in which the expansion is installed (called by the spaceship)
         * @param space Spaceship
         */
        void setSpaceShip(SpaceShip* space);
        /**
         * Amount of energy the expansion needs to function
         */
        virtual int getEnergy()=0;
        /**
         * Updates the status of the expansion
         * @param elapsed Milliseconds since last round
         */
        virtual void Update(double elapsed)=0;
        /**
         * Prepares the expansion for takeoff
         */
        virtual void engage()=0;
    private:
        SpaceShip* spaceship;
    };
};

#endif	/* EXPANSION_HPP */

