#include "SpaceShipCore.hpp"
#include "../space/SpaceShip.hpp"

using namespace tbd;

SpaceShipCore::SpaceShipCore(Drawer* d):CollisionEntity(d){
    
}

void SpaceShipCore::setSpaceShip(SpaceShip* space){
    spaceship=space;
}

void SpaceShipCore::engage(){
    HP=getStartingHP();
}