
#ifndef CONSOLEEXTRA_HPP
#define CONSOLEEXTRA_HPP

#include <string>

namespace tbd
{
	class ConsoleTarget;
	class ConsoleCommand;

	typedef enum {
		REGENE, SUMMON, REMOVE, LOAD, CLEAR
	} ConsoleCommandType;

	class ConsoleTarget
	{
	public:
		std::string name;
		int index;

		ConsoleTarget();
		ConsoleTarget(std::string const&, int const&);
	};

	class ConsoleCommand
	{
	public:
		ConsoleCommandType type;
		ConsoleTarget target;

		ConsoleCommand();
		ConsoleCommand(ConsoleCommandType const&, ConsoleTarget const&);
	};
}
#endif // CONSOLEEXTRA_HPP
