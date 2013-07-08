/* 
 * File:   StarredBackground.hpp
 * Author: alessio
 *
 */

#ifndef STARREDBACKGROUND_HPP
#define	STARREDBACKGROUND_HPP
#include "Background.hpp"
#include <vector>
namespace tbd {
    //Forward declaration
    class StarEntity;
    class Layer;
/**
 * Implementation of a simple starred background.
 */
    class StarredBackground : public Background{
    public:
        /**
         * Constructor of the background
         * @param l Layer of the background
         */
        StarredBackground(Layer* l);
        void Update(double elapsed);
    private:
        const double period=0.10;
        double remaining;
        std::vector<StarEntity*> stars;
        StarEntity* addStar();
    };
}

#endif	/* STARREDBACKGROUND_HPP */

