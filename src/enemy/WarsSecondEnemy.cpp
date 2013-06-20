/* 
 * File:   WarsSecondEnemy.cpp
 * Author: alessio
 * 
 */

#include "WarsSecondEnemy.hpp"
#include "../graphics/SimpleSprite.hpp"
#include "../Utilities.hpp"
#include "../missile/HomingMissile.hpp"
#include "../MissionManager.hpp"
#include "../collision/HitWindow.hpp"
using namespace tbd;
WarsSecondEnemy::WarsSecondEnemy(MissionManager* mm) : Enemy(new SimpleSprite("enemy.png", 0.1), mm) {
    rotation = 90;
    x = 0.05 + xMargin;
    y = randomDouble(-0.4, 0.4);
    currentwait = randomDouble(0.0, period);
    windows.push_back(new HitWindow(this,0.05,0.05));
}

void WarsSecondEnemy::Update(double elapsed) {
    x -= speed*elapsed;
    currentwait -= elapsed;
    if (currentwait <= 0) {
        currentwait = period;
        HomingMissile* sm = new HomingMissile(new SimpleSprite("missile2.png", 0.025), missionmanager);
        sm->copyPosition(this);
        sm->friendly = false;
        missionmanager->add(sm);
    }
    if (x<-xMargin - 0.2)
        missionmanager->remove(this);
}        
void WarsSecondEnemy::handleCollision(HitWindow* window,CollisionEntity* other){
    Missile* m;
    if(m=(dynamic_cast<Missile*> (other))){
        if(m->friendly)
            missionmanager->remove(this);
    }
}
