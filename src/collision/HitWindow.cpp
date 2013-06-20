/* 
 * File:   HitWindow.cpp
 * Author: alessio
 * 
 */

#include "HitWindow.hpp"
#include "CollisionEntity.hpp"
#include "../Utilities.hpp"
#include <iostream>
#include "PolyScreenShape.h"
using namespace tbd;
using namespace std;

HitWindow::HitWindow(CollisionEntity* coll, double w, double h, double dx, double dy, double rot) : Polycode::ScreenEntity() {
    this->dx = dx;
    this->dy = dy;
    drot = rot;
    setHeight(h);
    setWidth(w);
    myobject = coll;
    if (drawHitWindows) {
        Polycode::ScreenShape* shape = new Polycode::ScreenShape(Polycode::ScreenShape::SHAPE_RECT, w, h);
        shape->setColor(1.0, 0.0, 0.0, 1.0);
        shape->setPosition(0, 0);
        addChild(shape);
    }
}

void HitWindow::Update() {
    setRotation(myobject->rotation + drot);
    double rad_angle = myobject->rotation * toRad;
    double x = dx * cos(rad_angle) - dy * sin(rad_angle);
    double y = dx * sin(rad_angle) + dy * cos(rad_angle);
    setPosition(myobject->x + x, myobject->y + y);
}