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
    Core* core = new POLYCODE_CORE(view, 1024, 768, false, false, 0, 0, 90);
    core->enableMouse(false);
    double period=0.8;
    while(true) {
        MissionManager mm(core);
        
        mm.setSpaceship(new SpaceShip(new SimpleSprite("starship.png", 0.15), &mm));
        WarsFirstMission miss(&mm);
        miss.period=period;
        mm.setMission(&miss);
        if (mm.run()) {
            cout << "WE WON!!!" << endl;
        } else {
            cout << "WE LOST!!!" << endl;
            break;
        }
        period/=1.5;
    }
    return 0;
}

