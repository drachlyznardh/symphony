/* 
 * File:   StarDrawer.hpp
 * Author: alessio
 *
 */

#ifndef STARDRAWER_HPP
#define	STARDRAWER_HPP
#include "../graphics/Drawer.hpp"
namespace tbd {
/**
 * Graphics manager for the star
 */
    class StarDrawer: public Drawer{
    public:
        /**
         * Creates a star
         * @param height Diameter of the star
         */
        StarDrawer(double height);
        /**
         * Moves the graphics entity to follow the actual star
         */
        void Update();
    private:

    };
}

#endif	/* STARDRAWER_HPP */

