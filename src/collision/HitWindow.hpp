/* 
 * File:   HitWindow.hpp
 * Author: alessio
 *
 */

#ifndef HITWINDOW_HPP
#define	HITWINDOW_HPP
#include "PolyScreenEntity.h"
namespace tbd {
    class CollisionEntity;//Forward declaration
    /**
     * A simple rectangle used for collision detection
     */
    class HitWindow : public Polycode::ScreenEntity{
    public:        
        HitWindow(CollisionEntity* coll,double w,double h,double dx=0.0,double dy=0.0,double rot=0.0);
        void Update();
        CollisionEntity* myobject;
    private:
        double dx,dy,drot;        
    };
}

#endif	/* HITWINDOW_HPP */

