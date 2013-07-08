#ifndef SIMPLEMISSILE_HPP
#define	SIMPLEMISSILE_HPP
#include "Missile.hpp"
namespace tbd {
    /**
     * Implementation of a simple missile that you can aim!!
     */
    class SimpleMissile : public Missile {
    public:
        /**
         * Constructor of the Missile
         * @param d The paired Drawer class
         * @param mm The missionmanager that contains this missile
         */
        SimpleMissile(Drawer* d,MissionManager* mm);
        void Update(double elapsed);
        /**
         * Aims at a point in the world
         * @param x X coordinates
         * @param y Y coordinates
         */
        void aim(double x,double y);
        /**
         * Aims at a certain angle
         * @param angle Angle in degrees
         */
        void aim(double angle);
        /**
         * Skips on the current direction
         * @param distance The distance to skip
         */
        void skip(double distance);        
        /**
         * Speed of the missile
         */
        double speed=0.4;
    private:
        double dx;
        double dy;
    };
}
#endif	/* SIMPLEMISSILE_HPP */

