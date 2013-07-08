#include "ConsoleMission.hpp"
#include "../background/StarredBackground.hpp"
#include "../MissionManager.hpp"
#include "../ConsoleListener.hpp"

using namespace tbd;

ConsoleMission::ConsoleMission(){}

bool ConsoleMission::completed(){
	return false;
}

Background* ConsoleMission::getBackground(Layer* l) {
    return new StarredBackground(l);
}

void ConsoleMission::Update(double elapsed)
{}

