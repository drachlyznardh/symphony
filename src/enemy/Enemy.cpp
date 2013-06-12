/* 
 * File:   enemy.cpp
 * Author: alessio
 * 
 */

#include "Enemy.hpp"
#include "../graphics/Drawer.hpp"
using namespace tbd;
Enemy::Enemy(Drawer* d,MissionManager* mm):CollisionEntity(d),missionmanager(mm){
    
}
