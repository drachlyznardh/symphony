/* 
 * File:   SpaceShip.cpp
 * Author: alessio
 * 
 */

#include "SpaceShip.hpp"
#include "../Input.hpp"
#include "../MissionManager.hpp"
#include "../missile/SimpleMissile.hpp"
#include "../missile/HomingMissile.hpp"
#include "../graphics/SimpleSprite.hpp"
#include "../Utilities.hpp"
#include "../collision/HitWindow.hpp"
using namespace tbd;
using namespace std;

bool SpaceShip::isAlive() {
    return alive;
}

SpaceShip::SpaceShip(Drawer* d) : CollisionEntity(d) {
    x = 0.0;
    y = 0.0;
    rotation = 0.0;
    windows.push_back(new HitWindow(this, 0.05, 0.05));
}


SpaceShip::SpaceShip(Drawer* d, MissionManager* mm) : CollisionEntity(d), missionmanager(mm) {
    x = 0.0;
    y = 0.0;
    rotation = 0.0;
    windows.push_back(new HitWindow(this, 0.05, 0.05));
}

void SpaceShip::Update(double elapsed) {
    double mov = speed*elapsed;
    y -= mov * Input::get()->Up();
    y += mov * Input::get()->Down();
    x -= mov * Input::get()->Left();
    x += mov * Input::get()->Right();
    if (x < 0)
        x = max(x, -xMargin);
    else
        x = min(x, xMargin);
    if (y < 0)
        y = max(y, -0.5);
    else
        y = min(y, 0.5);


    double mx, my;
    mx = Input::get()->X();
    my = Input::get()->Y();
    rotation = getAngle(x, y, mx, my);

    waitingtime -= elapsed;
    if (waitingtime < 0 && Input::get()->isButton1()) {
        waitingtime = period;
        SimpleMissile* sm = new SimpleMissile(new SimpleSprite(RESOURCE(missile.png), 0.015), missionmanager);
        sm->copyPosition(this);
        sm->aim(rotation);
        sm->skip(0.1);
        sm->speed = 0.8;
        sm->friendly = true;
        missionmanager->add(sm);
    }

}

void SpaceShip::handleCollision(HitWindow* window, CollisionEntity* other) {
    Missile* m;
    if (m = dynamic_cast<Missile*> (other)) {
        if (!m->friendly)
            alive=false;
    } else {
        alive=false;
    }
}

void SpaceShip::setMissionManager(MissionManager* mm){
    missionmanager=mm;
}
