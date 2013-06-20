/* 
 * File:   Drawer.hpp
 * Author: alessio
 *
 */

#ifndef DRAWER_HPP
#define	DRAWER_HPP
#include <Polycode.h>

namespace tbd {
    //Forward declaration
    class DrawableEntity;
    /**
 * Interface for a thing that draws. At creation it should be paired with a Drawable Entity
 */
    class Drawer : public Polycode::ScreenEntity {
    public:
        Drawer();
        tbd::DrawableEntity* myEntity;
    private:

    };

}
#endif	/* DRAWER_HPP */

