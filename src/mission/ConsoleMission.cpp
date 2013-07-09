#include "ConsoleMission.hpp"
#include "../background/StarredBackground.hpp"
#include "../MissionManager.hpp"
#include "../ConsoleListener.hpp"
#include "../console/ConsoleParser.h"

#include <iostream>
#include <sstream>
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

		istringstream msgstream(msg);
		ConsoleParser parser(msgstream, cout);

		if (parser.parse()) {
			cout << "Something bad" << endl;
		} else cout << "Something good" << endl;
	}
}

