/* 
 * File:   StarEntity.hpp
 * Author: alessio
 *
 */

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
        StarEntity(Drawer* d,double px);
        void Update(double elapsed);
    private:
        const double maxspeed=2.0;
        const double minspeed=0.5;
        double dx;
    };
}

#endif	/* STARENTITY_HPP */

