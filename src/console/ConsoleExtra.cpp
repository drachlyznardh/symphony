
#include "ConsoleLexerbase.h"
#include "ConsoleParser.h"

#include <sstream>

tbd::ConsoleParser::ConsoleParser (
	std::istream &in,
	std::ostream &out):
	d_scanner(in, out)
{
}

