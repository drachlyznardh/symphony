
#include "ConsoleParser.h"

#include <sstream>

tbd::ConsoleParser::ConsoleParser (
	std::istream &in,
	std::ostream &out):
	d_scanner(in, out)
{}

std::vector<tbd::ConsoleCommand>
tbd::ConsoleParser::getCommandList () const
{
	return this->commandList;
}

tbd::ConsoleTarget::ConsoleTarget(){}

tbd::ConsoleTarget::ConsoleTarget (
	std::string const& name,
	int const& index):
	name(name), index(index)
{}

tbd::ConsoleCommand::ConsoleCommand(){}

tbd::ConsoleCommand::ConsoleCommand (
	tbd::ConsoleCommandType const& type,
	tbd::ConsoleTarget const& target):
	type(type),target(target)
{}

void
tbd::ConsoleParser::recordType (
	tbd::ConsoleCommandType const& type)
{
	this->currentType = type;
}

void
tbd::ConsoleParser::recordTarget (
	std::string const& name,
	int const& index)
{
	this->currentTarget.name = name;
	this->currentTarget.index = index;
}

void
tbd::ConsoleParser::recordCommand()
{
	this->commandList.push_back(ConsoleCommand(
			this->currentType, this->currentTarget));
}
