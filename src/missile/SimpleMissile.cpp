/* 
 * File:   SimpleMissile.cpp
 * Author: alessio
 * 
 */

#include "SimpleMissile.hpp"
#include "Missile.hpp"
#include "../graphics/SimpleSprite.hpp"
#include "../MissionManager.hpp"
#include "../Utilities.hpp"
#include "../collision/HitWindow.hpp"
#include <cmath>
#include <iostream>
using namespace tbd;

SimpleMissile::SimpleMissile(Drawer* d, MissionManager* mm) : Missile(d, mm) {
    windows.push_back(new HitWindow(this, d->getWidth(), d->getHeight()));
}

void SimpleMissile::Update(double elapsed) {
    x += speed * elapsed*dx;
    y += speed * elapsed*dy;
    if (isOutOfScreen(x, y, 0.2))
        missionmanager->remove(this);
}

void SimpleMissile::skip(double distance) {
    x += distance*dx;
    y += distance*dy;
}

void SimpleMissile::aim(double angle) {
    rotation = angle;
    dx = cos(angle * toRad);
    dy = sin(angle * toRad);
}

void SimpleMissile::aim(double tx, double ty) {
    double angle = getAngle(x,y,tx,ty);
    rotation = angle;
    double deltax = tx - x;
    double deltay = ty - y;
    double vsize = sqrt(deltax * deltax + deltay * deltay);
    dx = deltax / vsize;
    dy = deltay / vsize;
}
