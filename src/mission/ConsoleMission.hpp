
#ifndef CONSOLEMISSION_HPP
#define CONSOLEMISSION_HPP
#include "Mission.hpp"
#include "../console/ConsoleExtra.hpp"
#include <vector>
namespace tbd {
	class Background;
	class ConsoleMission: public Mission {
	public:
		void Update(double elapsed);
		bool completed();

		Background* getBackground(Layer* l);
		ConsoleMission();
	private:
		std::vector<ConsoleCommand> commandList;

		void regeneTarget(ConsoleTarget const&);
		void summonTarget(ConsoleTarget const&);
		void removeTarget(ConsoleTarget const&);
	};
}
#endif // CONSOLEMISSION_HPP
