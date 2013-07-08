#ifndef STARENTITY_HPP
#define	STARENTITY_HPP
#include "../DrawableEntity.hpp"

namespace tbd {
    //Forward declaration
    class Drawer;
    /**
     * Star entity, it moves from right to left to give the illusion of speeeeed
     */
    class StarEntity : public DrawableEntity{
    public:
        /**
         * Construct a new star
         * @param d Drawer entity of the star
         * @param px Starting X coordinate
         */
        StarEntity(Drawer* d,double px);
        /**
         * 
         * @param elapsed milliseconds elapsed since last frame
         */
        void Update(double elapsed);
    private:
        const double maxspeed=2.0;
        const double minspeed=0.5;
        double dx;
    };
}

#endif	/* STARENTITY_HPP */

