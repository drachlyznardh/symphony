#include "Weapon.hpp"
#include "../collision/HitWindow.hpp"
#include "../space/SpaceShip.hpp"

using namespace tbd;

Weapon::Weapon(Drawer* d): CollisionEntity(d){
}

void Weapon::setSpaceShip(SpaceShip* ship){
    spaceship=ship;   
}

void Weapon::engage(){
    HP=getStartingHP();
}