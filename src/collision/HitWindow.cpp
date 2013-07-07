#include "HitWindow.hpp"
#include "CollisionEntity.hpp"
#include "../Utilities.hpp"
#include "PolyScreenShape.h"
#include "../space/SpaceShip.hpp"
#include "../core/SpaceShipCore.hpp"
#include "../weapon/Weapon.hpp"
#include <iostream> 
#include <utility>

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
    SpaceShipCore* s;
    Weapon* we;
    if (s = dynamic_cast<SpaceShipCore*> (myobject)) {
        father = s->spaceship;
    }

    if (we = dynamic_cast<Weapon*> (myobject)) {
        father = we->spaceship;
    }
}

void HitWindow::Update() {
    double r, xx, yy;
    if (!father) {
        r = myobject->rotation;
        xx = myobject->x;
        yy = myobject->y;
    } else {
        r = myobject->rotation + father->rotation;
        pair<double, double> p = myobject->computeTotalPosition(father);
        xx = p.first;
        yy = p.second;
    }
    setRotation(r + drot);
    double rad_angle = r * toRad;
    double x = dx * cos(rad_angle) - dy * sin(rad_angle);
    double y = dx * sin(rad_angle) + dy * cos(rad_angle);
    setPosition(xx + x, yy + y);
}