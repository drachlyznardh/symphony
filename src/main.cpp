/* 
 * File:   main.cpp
 * Author: alessio
 *
 */

#include <cstdlib>
#include "Logger.hpp"
#include "Polycode.h"
#include "PolycodeView.h"
#include "space/SpaceShip.hpp"
#include "graphics/SimpleSprite.hpp"
#include "Input.hpp"
#include "MissionManager.hpp"
#include "mission/WarsFirstMission.hpp"
#include <iostream>
using namespace tbd;
using namespace Polycode;
using namespace std;

/** 
 * 
 * Main function, just to play with all our stuff.
 */
int main() {
    PolycodeView* view = new PolycodeView("Pew Pew!");
    Core* core = new POLYCODE_CORE(view, 1024, 768, false, true, 0, 0, 90);
    core->enableMouse(false);
    double period=2.0;
    SpaceShip space(new SimpleSprite(RESOURCE(starship.png),0.15));
    while(true) {
        MissionManager mm(core);
        WarsFirstMission miss;
        miss.period=period;
        mm.setSpaceship(&space);
        mm.setMission(&miss);
        bool res=mm.run();
        cout<<"Destroyed "<<mm.stats.enemydestroyed<<" enemies in "<<mm.stats.runtime<<" seconds"<<endl;
        if (res) {
            cout << "WE WON!!!" << endl;
        } else {
            cout << "WE LOST!!!" << endl;
            break;
        }
        period/=1.5;
    }
    return 0;
}

