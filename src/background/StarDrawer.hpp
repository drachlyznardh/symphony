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
        StarDrawer(double height);
        void Update();
    private:

    };
}

#endif	/* STARDRAWER_HPP */

