#include "HPMonitor.hpp"
#include "../graphics/SimpleText.hpp"
#include "../graphics/SimpleSprite.hpp"
#include "../Input.hpp"
#include "../space/SpaceShip.hpp"
#include "../core/SpaceShipCore.hpp"
#include "../weapon/Weapon.hpp"
#include <iostream>
#include <sstream>
using namespace tbd;
using namespace std;

HPMonitor::HPMonitor(SpaceShip* space) : spaceship(space),  DrawableEntity(new SimpleText("Ciao", 20)) {
    x=0;
    y=0.44;
}

void HPMonitor::Update(double elapsed) {
    ostringstream ss;
    ss<<"HP = "<<spaceship->core->getHP()<<"/"<<spaceship->core->getStartingHP()<<" ";
    ss<<" WEAPONS = [";
    bool first=true;
    for(Weapon* w: spaceship->weapons)
	if(w){
	    if(first)
		first=false;
	    else
		ss<<",";
	    ss<<w->getHP()<<"/"<<w->getStartingHP();
	}
    ss<<"]";
    ((SimpleText* )mydrawer)->setText(ss.str());
}