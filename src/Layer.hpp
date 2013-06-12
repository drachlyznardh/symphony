/* 
 * File:   Layer.hpp
 * Author: alessio
 *
 */

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
        Layer();
        void addEntity(DrawableEntity* de);
        void removeEntity(DrawableEntity* de);
    private:
        
    };
}

#endif	/* LAYER_HPP */

