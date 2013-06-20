
mklist(collision_SRCS ${root}
	CollisionEntity.cpp
	CollisionManager.cpp
	HitWindow.cpp
)

set(collision_SRCS ${collision_SRCS} PARENT_SCOPE)
set(collision_LIBS ${collision_LIBS} PARENT_SCOPE)
