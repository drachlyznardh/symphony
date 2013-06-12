/* 
 * File:   SimpleMissile.hpp
 * Author: alessio
 *
 */

#ifndef SIMPLEMISSILE_HPP
#define	SIMPLEMISSILE_HPP
#include "Missile.hpp"
namespace tbd {
    /**
     * Implementation of a simple missile that you can aim!!
     */
    class SimpleMissile : public Missile {
    public:
        SimpleMissile(Drawer* d,MissionManager* mm);
        void Update(double elapsed);
        void aim(double x,double y);
        void aim(double angle);
        void skip(double distance);        
        double speed=0.4;
    private:
        double dx;
        double dy;
    };
}
#endif	/* SIMPLEMISSILE_HPP */

