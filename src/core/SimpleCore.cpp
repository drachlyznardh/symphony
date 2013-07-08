#include "SimpleCore.hpp"
#include "../collision/HitWindow.hpp"
#include "../missile/Missile.hpp"
#include "../graphics/SimpleSprite.hpp"
#include "../enemy/Enemy.hpp"
#include <utility>
#include <iostream>

using namespace tbd;
using namespace std;

SimpleCore::SimpleCore() : SpaceShipCore(new SimpleSprite(RESOURCE(starship.png), 0.15)) {
    hardpoints = {
        {0, 0.05},
        {0, -0.05}};
    x = 0;
    y = 0;
}

int SimpleCore::getStartingHP() {
    return 3;
}

double SimpleCore::getSpeed() {
    return 0.4;
}

int SimpleCore::getEnergyPool() {
    return 10;
}

void SimpleCore::Update(double elapsed) {

}

void SimpleCore::handleCollision(HitWindow* window, CollisionEntity* other) {
    Missile* m;
    if (m = dynamic_cast<Missile*> (other)) {
        if (!m->friendly)
            HP--;
    }
}

void SimpleCore::engage() {
    SpaceShipCore::engage();
    windows.push_back(new HitWindow(this, 0.05, 0.05));
}

int SimpleCore::getExpansionsNumber(){
    return 2;
}