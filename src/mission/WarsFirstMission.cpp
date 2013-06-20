/* 
 * File:   WarsFirstMission.cpp
 * Author: alessio
 * 
 * Created on 5 giugno 2013, 14.28
 */

#include "WarsFirstMission.hpp"
#include "../background/StarredBackground.hpp"
#include "../enemy/WarsFirstEnemy.hpp"
#include "../enemy/WarsSecondEnemy.hpp"
#include "../MissionManager.hpp"
using namespace tbd;


void WarsFirstMission::Update(double elapsed) {
    totalTime+=elapsed;
    wait-=elapsed;
    if(wait<=0){
        wait=period;
        if(totalTime<=10)
            missionmanager->add(new WarsFirstEnemy(missionmanager));
        else if(totalTime<=20)
            missionmanager->add(new WarsSecondEnemy(missionmanager));
        else if (totalTime <= 30 ){
            missionmanager->add(new WarsFirstEnemy(missionmanager));            
            missionmanager->add(new WarsSecondEnemy(missionmanager));
        }
        
    }
}

bool WarsFirstMission::completed() {
    return totalTime>30.0 && missionmanager->getNumberOfEnemies()==0;
}

Background* WarsFirstMission::getBackground(Layer* l) {
    return new StarredBackground(l);
}

WarsFirstMission::WarsFirstMission(MissionManager* mm):Mission(mm) {
    totalTime=0.0;
    wait=period;
}