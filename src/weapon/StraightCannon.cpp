#include "StraightCannon.hpp"
#include "../collision/HitWindow.hpp"
#include "../collision/CollisionEntity.hpp"
#include "../graphics/SimpleSprite.hpp"
#include "../Input.hpp"
#include "../missile/SimpleMissile.hpp"
#include "../MissionManager.hpp"
#include "../space/SpaceShip.hpp"
#include <utility>

using namespace tbd;
using namespace std;

StraightCannon::StraightCannon() : Weapon(new SimpleSprite(RESOURCE(cannon.png), 0.05)) {

}

int StraightCannon::getEnergy() {
    return 1;
}

int StraightCannon::getStartingHP() {
    return 1;
}

void StraightCannon::Update(double elapsed) {
    if (HP > 0) {
        waitingtime -= elapsed;
        if (waitingtime < 0 && Input::get()->isButton1()) {
            waitingtime = period;
            SimpleMissile* sm = new SimpleMissile(new SimpleSprite(RESOURCE(missile.png), 0.015), spaceship->missionmanager);
            pair<double,double> p=computeTotalPosition(spaceship);
            sm->x=p.first;
            sm->y=p.second;
            sm->aim(rotation+spaceship->rotation);
            sm->skip(0.1);
            sm->speed = 0.8;
            sm->friendly = true;
            spaceship->missionmanager->add(sm);
        }


    }
}

void StraightCannon::handleCollision(HitWindow* window, CollisionEntity* other) {
    Missile* m;
    if (m = dynamic_cast<Missile*> (other)) {
        if (!m->friendly)
	    if(HP>0)
	            HP--;
    }    
}

void StraightCannon::engage() {
    Weapon::engage();
    windows.push_back(new HitWindow(this, 0.05, 0.02));
}
