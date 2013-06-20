/* 
 * File:   Random.cpp
 * Author: alessio
 * 
 */

#include "Utilities.hpp"

using namespace tbd;

std::mt19937 rng;

void tbd::setSeed(int seed) {
    rng.seed(seed);
}

int tbd::randomInt(int low, int high) {
    std::uniform_int_distribution<int> uint_dist(low, high);
    return uint_dist(rng);
}

double tbd::randomDouble(double low, double high) {
    std::uniform_real_distribution<double> udouble_dist(low, high);
    return udouble_dist(rng);
}        

bool tbd::isOutOfScreen(double x,double y, double eM){
    return x<-xMargin-eM || x>xMargin+ eM || y < -0.5-eM || y>0.5+eM;
}

bool tbd::isOutOfScreen(double x,double y){
    return isOutOfScreen(x,y,0.0);
}
double tbd::getAngle(double sourceX,double sourceY, double targetX, double targetY){
     if (sourceX == targetX && sourceY==targetY)
         return 0.0;
     
    double rotation = atan((targetY - sourceY) / (targetX - sourceX))*toDeg;
        if (targetX < sourceX)
            rotation = rotation + 180;
    return fmod(rotation,360);
}
