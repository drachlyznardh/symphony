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
		istringstream msgstream(msg);
		ConsoleParser parser(msgstream, cout);

		if (parser.parse() == 0) commandList = parser.getCommandList();
	}

	if (commandList.size()) {
		for (auto e: commandList) switch (e.type) {
			case REGENE: this->regeneTarget(e.target); break;
			case SUMMON: this->summonTarget(e.target); break;
			case REMOVE: this->removeTarget(e.target); break;

			case LOAD: this->load(e.target.name); break;
			case CLEAR: this->clear(); break;

			default: cout << "Bad type [" << e.type << "]";
		}
		commandList.clear();
	}
}

void ConsoleMission::regeneTarget (
	ConsoleTarget const& target)
{
	cout << "[Regene]" << endl;
}

void ConsoleMission::summonTarget (
	ConsoleTarget const& target)
{
	cout << "[Summon]" << endl;
}

void ConsoleMission::removeTarget (
	ConsoleTarget const& target)
{
	cout << "[Remove]" << endl;
}

void ConsoleMission::load (
	std::string const& filename)
{}

void ConsoleMission::clear ()
{}
