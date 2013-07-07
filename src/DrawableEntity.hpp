#ifndef DRAWABLEENTITY_HPP
#define	DRAWABLEENTITY_HPP

#include <utility>

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
        /**
         * Angle (in degrees) of the entity
         */
        double rotation;
        /**
         * X position of the entity
         */
        double x;
        /**
         * Y position of the entity
         */
        double y;
        /**
         * Drawer of the Entity
         */
        Drawer* mydrawer;
        /**
         * Layer on which the Entity resides
         */
        Layer* mylayer;
        /**
         * Automatically removes the Entity from the layer it has been added to.
         * If it has not been added to a Layer, it does nothing.
         */
        void removeFromLayer();
        /**
         * Moves the entity to the position of another Entity
         *@param other Other entity
         */
        void copyPosition(DrawableEntity* other);
        /**
         * Computes the position of the entity in the world, considering the 
         * position and rotation of another entity that contains it
         * @param father The entity that contains the current entity
         */
        std::pair<double, double> computeTotalPosition(DrawableEntity* father);
        virtual ~DrawableEntity();
    protected:
        /**
         * Constructor of the entity, connects it to a Drawer that will draw it
         * @param drawer Drawer of the entity
         */
        DrawableEntity(Drawer* drawer);
    };


}
#endif	/* DRAWABLEENTITY_HPP */

