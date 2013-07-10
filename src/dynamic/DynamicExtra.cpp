
#include "DynamicParser.h"

void
tbd::DynamicParser::msg (
	std::string const& type,
	std::string const& msg)
{
	std::cerr << type << ": ";
	std::cerr << d_scanner.filename() << " @" << d_scanner.lineNr() << ": ";
	std::cerr << msg << std::endl;
}


