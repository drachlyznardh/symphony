
#include "DynamicParser.h"
#include <fstream>

void
tbd::DynamicParser::msg (
	std::string const& type,
	std::string const& msg)
{
	std::cerr << type << ": ";
	std::cerr << d_scanner.filename() << " @" << d_scanner.lineNr() << ": ";
	std::cerr << msg << std::endl;
}

void
tbd::DynamicParser::includeFile (
	std::string const& filename)
{
	std::cout << "Now including [" << filename << "]" << std::endl;
	//this->d_scanner.pushStream(filename);
}
