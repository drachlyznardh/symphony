#include <Polycode.h>
#include "Layer.hpp"
#include "background/Background.hpp"
#include "enemy/Enemy.hpp"
#include "missile/Missile.hpp"
#include "mission/Mission.hpp"
#include "MissionManager.hpp"
#include "space/SpaceShip.hpp"
#include "Input.hpp"
#include "collision/CollisionManager.hpp"
#include "gui/GUI.hpp"

using namespace Polycode;
using namespace tbd;

int MissionManager::getNumberOfEnemies(){
    return enemies.size();
}
void MissionManager::setSpaceship(SpaceShip* s){
    spaceship=s;
    s->setMissionManager(this);
}

void MissionManager::setMission(Mission* m){
    mission=m;
    m->setMissionManager(this);
}

MissionManager::MissionManager(Core* c) : core(c) {
    collisionmanager=new CollisionManager();
    gui= new GUI(this);
    spaceship=0;
    mission=0;
}

void MissionManager::add(Missile* missile){
    missiles.push_back(missile);
    Missiles->addEntity(missile);
    collisionmanager->add(missile);
}

void MissionManager::remove(Missile* missile){
    missiles.erase(std::remove(missiles.begin(),missiles.end(),missile),missiles.end());
    missile->removeFromLayer();
    collisionmanager->remove(missile);
    toDelete.insert(missile);
}


void MissionManager::add(Enemy* enemy){
    enemies.push_back(enemy);
    Ships->addEntity(enemy);
    collisionmanager->add(enemy);
}

void MissionManager::remove(Enemy* enemy){
    if(!enemy->alive)
        stats.enemydestroyed++;
    enemies.erase(std::remove(enemies.begin(),enemies.end(),enemy),enemies.end());
    enemy->removeFromLayer();
    collisionmanager->remove(enemy);
    toDelete.insert(enemy);
}

void MissionManager::cleanup(){
    for(Enemy* en:enemies)
        delete en;
    for(Missile* mis:missiles)
        delete mis;
    delete BackgroundLayer;
    delete Ships;
    delete Missiles;
    delete background;
    delete collisionmanager;
    delete gui;
    enemies.clear();
    missiles.clear();
}

bool MissionManager::run() {
    if(spaceship==0 || mission==0)
        throw "Mission or Spaceship not assigned";
    BackgroundLayer = new Layer();
    Ships = new Layer();
    Missiles = new Layer();
    Ships->addEntity(spaceship);
    for(CollisionEntity* ce:spaceship->collisions)
        collisionmanager->add(ce);
    background=mission->getBackground(BackgroundLayer);
    Input::changeInput(core);
    gui->Init();
    while(true) {
        double elapsed=0;
	if (Input::get()->isRunning()){
			elapsed=core->getElapsed();
        stats.runtime+=elapsed;
        background->Update(elapsed);
        mission->Update(elapsed);
        spaceship->Update(elapsed);
        for(auto enemy:enemies)
            enemy->Update(elapsed);
        for(auto missile:missiles)
            missile->Update(elapsed);
        for(auto del:toDelete){
            delete del;
        }
        gui->Update(elapsed);
        toDelete.clear();
		if(!Input::get()->isAlive()){
			cleanup();
			return false;
		}
        if(mission->completed()){
            cleanup();
            return true;
        }  
        if(!spaceship->isAlive()){
            cleanup();
            return false;
        }
	}
        if(!core->updateAndRender()){
            cleanup();
            return false;
        }
    }
	return false;
}

