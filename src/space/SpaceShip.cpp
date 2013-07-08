#include "SpaceShip.hpp"
#include "../Input.hpp"
#include "../MissionManager.hpp"
#include "../missile/SimpleMissile.hpp"
#include "../missile/HomingMissile.hpp"
#include "../graphics/SimpleSprite.hpp"
#include "../Utilities.hpp"
#include "../collision/HitWindow.hpp"
#include "../core/SpaceShipCore.hpp"
#include "../weapon/Weapon.hpp"
#include "../expansion/Expansion.hpp"
#include <cassert>

using namespace tbd;
using namespace std;

void SpaceShip::addExpansion(Expansion* exp){
    assert(core);
    assert(expansions.size()<core->getExpansionsNumber());
    expansions.push_back(exp);
}

bool SpaceShip::isAlive() {
    return core->getHP() > 0;
}

SpaceShip::SpaceShip() : DrawableEntity(new Drawer()) {
    x = 0.0;
    y = 0.0;
    rotation = 0.0;
}

void SpaceShip::Update(double elapsed) {
    double speed = core->getSpeed();
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
    core->Update(elapsed);
    for (Weapon* w : weapons)
        if (w)
            w->Update(elapsed);

}

void SpaceShip::setMissionManager(MissionManager* mm) {
    missionmanager = mm;
}

void SpaceShip::setCore(SpaceShipCore* core) {
    this->core = core;
    this->core->setSpaceShip(this);
    weapons.clear();
    weapons.resize(core->hardpoints.size());
}

void SpaceShip::assemble() {
    assert(core != 0);
    core->engage();
    mydrawer->addChild(core->mydrawer);
    int totenergy = core->getEnergyPool();
    for (int i = 0; i < weapons.size(); i++) {
        Weapon* w = weapons[i];
        if (w) {
            totenergy -= w->getEnergy();
            w->engage();
            w->x = core->hardpoints[i].first;
            w->y = core->hardpoints[i].second;
            mydrawer->addChild(w->mydrawer);
            collisions.push_back(w);
        }
    }
    for(Expansion* exp:expansions){
        exp->engage();
        totenergy-=exp->getEnergy();
    }
    collisions.push_back(core);
    assert(totenergy >= 0);
}

void SpaceShip::setWeapon(Weapon* weapon, int hp) {
    assert(core != 0 && hp >= 0 && hp < core->hardpoints.size());
    weapons[hp] = weapon;
    weapon->setSpaceShip(this);
}