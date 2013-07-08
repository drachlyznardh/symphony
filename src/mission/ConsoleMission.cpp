#include "ConsoleMission.hpp"
#include "../background/StarredBackground.hpp"
#include "../MissionManager.hpp"
#include "../ConsoleListener.hpp"

#include <iostream>
#include <string>

using namespace tbd;
using namespace std;

ConsoleMission::ConsoleMission(){}

bool ConsoleMission::completed(){
	return false;
}

Background* ConsoleMission::getBackground(Layer* l) {
    return new StarredBackground(l);
}

void ConsoleMission::Update(double elapsed)
{
	if (missionmanager->cl.hasMessage()) {
		string msg = missionmanager->cl.getMessage();
		cout << "Found [" << msg << "]" << endl;
	}
}

