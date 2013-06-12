/* 
 * File:   Random.hpp
 * Author: alessio
 *
 */

#ifndef RANDOM_HPP
#define	RANDOM_HPP

#include <random>
namespace tbd {
    /**
     * Half the width of the screen (the height is always 1.0)
     */
    const double xMargin = 0.67;
    
    /**
     * To convert from Degrees to Radiants
     */
    const double toRad = 3.14159265359/180.0;
    
    /**
     * To convert from Radiants to Degrees
     */
    const double toDeg = 180.0/3.14159265359;
    
    /**
     * Should we draw the Hit Windows (to debug stuff)
     */
    const bool drawHitWindows = false;
    /**
     * Set seed for our random generator
     * @param seed 
     */
    void setSeed(int seed);
    /**
     * Returns a random integer in [low,high] (extremes included)
     * @param low
     * @param high
     * @return 
     */
    int randomInt(int low, int high);
    /**
     * Returns a random double in [low,high] (extremes included)
     * @param low
     * @param high
     * @return 
     */
    double randomDouble(double low, double high);
    /**
     * Checks if position is out of the screen
     */
    bool isOutOfScreen(double x, double y);
    /**
     * Checks if position is out of the screen with extra margin
     */
    bool isOutOfScreen(double x,double y, double eM);
    /**
     * Computes the angle from the source to the target
     */
    double getAngle(double sourceX,double sourceY, double targetX, double targetY);
}
#endif	/* RANDOM_HPP */

