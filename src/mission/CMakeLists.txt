
mklist(mission_SRCS ${root} 
	ConsoleMission.cpp
	Mission.cpp
	WarsFirstMission.cpp
)

set(mission_SRCS ${mission_SRCS} PARENT_SCOPE)
set(mission_LIBS ${mission_LIBS} PARENT_SCOPE)
