
#ifndef CONSOLEMISSION_HPP
#define CONSOLEMISSION_HPP
#include "Mission.hpp"
namespace tbd {
	class Background;
	class ConsoleMission: public Mission {
	public:
		void Update(double elapsed);
		bool completed();

		Background* getBackground(Layer* l);
		ConsoleMission();
	};
}
#endif // CONSOLEMISSION_HPP
