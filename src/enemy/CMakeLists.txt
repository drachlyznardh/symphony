
mklist(enemy_SRCS ${root}
	Enemy.cpp
	WarsFirstEnemy.cpp
	WarsSecondEnemy.cpp
)

set(enemy_SRCS ${enemy_SRCS} PARENT_SCOPE)
set(enemy_LIBS ${enemy_LIBS} PARENT_SCOPE)
