/* 
 * File:   SimpleSprite.hpp
 * Author: alessio
 *
 */

#ifndef SIMPLESPRITE_HPP
#define	SIMPLESPRITE_HPP
#include "Drawer.hpp"
#include <string>
namespace tbd {
/**
 * Simple drawer, will map a sprite to the entity.
 */
    class SimpleSprite : public Drawer{
    public:
        /**
         * Creates the sprite
         * @param filename Filename of the png sprite
         * @param height Height of the sprite (only for drawing!)
         */
        SimpleSprite(const std::string& filename, double height);
        void Update();
    private:
        
    };
}

#endif	/* SIMPLESPRITE_HPP */

