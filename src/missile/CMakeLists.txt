
mklist(missile_SRCS ${root}
	HomingMissile.cpp
	Missile.cpp
	SimpleMissile.cpp
)

set(missile_SRCS ${missile_SRCS} PARENT_SCOPE)
set(missile_LIBS ${missile_LIBS} PARENT_SCOPE)
