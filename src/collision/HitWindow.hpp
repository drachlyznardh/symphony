#ifndef HITWINDOW_HPP
#define	HITWINDOW_HPP
#include "PolyScreenEntity.h"

namespace tbd {
    class CollisionEntity;//Forward declaration
    class DrawableEntity;
    /**
     * A simple rectangle used for collision detection
     */
    class HitWindow : public Polycode::ScreenEntity{
    public:        
        /**
         * Constructor of the window
         * @param coll Object connected to the hitwindow
         * @param w Width of the window
         * @param h Height of the window
         * @param dx Relative position of the window relative to the object on the X axis
         * @param dy Relative position of the window relative to the object on the Y axis
         * @param rot Rotation angle of the window relative to the object
         */
        HitWindow(CollisionEntity* coll,double w,double h,double dx=0.0,double dy=0.0,double rot=0.0);
        /**
         * Updates the position of the HitWindow
         */
        void Update();
        /**
         * The object connected to the window
         */
        CollisionEntity* myobject;
    private:
        double dx,dy,drot;        
        DrawableEntity* father=0;
    };
}

#endif	/* HITWINDOW_HPP */

