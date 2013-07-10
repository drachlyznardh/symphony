
#include <cstdlib>
#include <iostream>

#include "DynamicParser.h"

int main()
{
	tbd::DynamicParser parser;
	
	if (parser.parse() == 0) std::cout << "Yay" << std::endl;
	else std::cout << "Nay" << std::endl;
	
	std::exit(0);
}
