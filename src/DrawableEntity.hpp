/* 
 * File:   DrawableEntity.hpp
 * Author: alessio
 *
 */

#ifndef DRAWABLEENTITY_HPP
#define	DRAWABLEENTITY_HPP

namespace tbd {
 class Drawer; //forward declaration  
 class Layer; //forward declaration
 /**
 * Interface of entity that can be drawed.
 * Subclasses must present information about position and rotation
 * Subclasses MUST call this constructor and give information on which class should 
 *  draw the subclass
 */    
    class DrawableEntity {
    public:
        double rotation;
        double x;
        double y;
        Drawer* mydrawer;
        Layer* mylayer;
        /**
         * Automatically removes the Entity from the layer it has been added to.
         * If it has not been added to a Layer, it does nothing.
         */
        void removeFromLayer();
        void copyPosition(DrawableEntity* other);
        virtual ~DrawableEntity();
    protected:
        DrawableEntity(Drawer* drawer);
    };

}
#endif	/* DRAWABLEENTITY_HPP */

