/* 
 * File:   Background.hpp
 * Author: alessio
 *
 */

#ifndef BACKGROUND_HPP
#define	BACKGROUND_HPP
namespace tbd {
    //Forward declaration
    class Layer;
    /**
     * Base class to draw stuff in the background.
     * It is non-interactive background, on a different layer.
     * It should be defined by the Mission class.
     */
    class Background {
    public:
        /**
         * Function called every frame
         * @param elapsed milliseconds elapsed since last frame
         */
        virtual void Update(double elapsed) = 0;

    private:
    protected:
        Background(Layer* l);
        Layer* layer;
    };
}

#endif	/* BACKGROUND_HPP */
