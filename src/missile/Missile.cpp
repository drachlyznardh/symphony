#include "Missile.hpp"
#include "../enemy/Enemy.hpp"
#include "../core/SpaceShipCore.hpp"
#include "../MissionManager.hpp"
#include "../graphics/Drawer.hpp"
#include "../weapon/Weapon.hpp"
#include "../space/SpaceShipComponent.hpp"
#include <iostream>

using namespace tbd;

tbd::Missile::Missile(Drawer* d, MissionManager* mm): CollisionEntity(d),missionmanager(mm){
    
}

Missile::~Missile(){
    
}
void Missile::handleCollision(HitWindow* window,CollisionEntity* coll){
     if (friendly) {
        if (dynamic_cast<Enemy*> (coll)) {
            missionmanager->remove(this);
        }
    } else {
         SpaceShipComponent* ssc;
        if (ssc=dynamic_cast<SpaceShipComponent*> (coll)) {
                missionmanager->remove(this);
        }
        
    }
}