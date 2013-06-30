/* 
 * File:   MyFirstEnemy.cpp
 * Author: alessio
 * 
 */

#include "WarsFirstEnemy.hpp"
#include "../graphics/SimpleSprite.hpp"
#include "../Utilities.hpp"
#include "../missile/SimpleMissile.hpp"
#include "../MissionManager.hpp"
#include "../collision/HitWindow.hpp"
#include "../space/SpaceShip.hpp"
using namespace tbd;

WarsFirstEnemy::WarsFirstEnemy(MissionManager* mm) : Enemy(new SimpleSprite(RESOURCE(enemy.png), 0.1), mm) {
    rotation = 90;
    x = 0.05 + xMargin;
    y = randomDouble(-0.4, 0.4);
    currentwait = randomDouble(0.0, period);
    windows.push_back(new HitWindow(this,0.05,0.05));
}

void WarsFirstEnemy::Update(double elapsed) {
    x -= speed*elapsed;
    currentwait -= elapsed;
    if (currentwait <= 0) {
        currentwait = period;
        
        SimpleMissile* sm = new SimpleMissile(new SimpleSprite(RESOURCE(missile.png), 0.025), missionmanager);
        sm->copyPosition(this);
        sm->aim(missionmanager->spaceship->x, missionmanager->spaceship->y);
        sm->skip(0.03);
        sm->friendly=false;
        missionmanager->add(sm);
    }
    if (x<-xMargin - 0.2)
        missionmanager->remove(this);
}

void WarsFirstEnemy::handleCollision(HitWindow* window,CollisionEntity* other){
    Missile* m;
    if(m=(dynamic_cast<Missile*> (other))){
        if(m->friendly){
            alive=false;
            missionmanager->remove(this);            
        }
    }
}
