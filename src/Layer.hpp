#ifndef LAYER_HPP
#define	LAYER_HPP
#include <Polycode.h>
namespace tbd {
    class DrawableEntity;
    /**
     * Right now, just a wrapper over PolycodeScreen
     * We might want to add other stuff to it or port it to other frameworks.
     */
    class Layer : public Polycode::Screen {
    public:
        /**
         * Constructor of the Layer
         */
        Layer();
        /**
         * Adds an entity (and its drawer) to the layer
         * @param de The Entity to add
         */
        void addEntity(DrawableEntity* de);
        /**
         * Removes an entity (and its drawer) to the layer
         * @param de The Entity to remove
         */
        void removeEntity(DrawableEntity* de);
    private:
        
    };
}

#endif	/* LAYER_HPP */

