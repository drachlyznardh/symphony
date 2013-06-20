
set(root ${sopp_ROOT})

mklist(src_SRCS ${root}
	DrawableEntity.cpp
	Input.cpp
	Layer.cpp
	Logger.cpp
	main.cpp
	MissionManager.cpp
	Utilities.cpp
)

add_subdirectory(background)
add_subdirectory(collision)
add_subdirectory(enemy)
add_subdirectory(graphics)
add_subdirectory(gui)
add_subdirectory(missile)
add_subdirectory(mission)
add_subdirectory(space)

list(APPEND src_SRCS
	${background_SRCS}
	${collision_SRCS}
	${enemy_SRCS}
	${graphics_SRCS}
	${gui_SRCS}
	${missile_SRCS}
	${mission_SRCS}
	${space_SRCS}
)
list(APPEND src_LIBS
	rt dl pthread
	Polycore
	freetype
	libvorbisfile libvorbis
	libogg
	openal
	physfs
	png15
	GL GLU SDL
	Polycode2DPhysics
	Box2D
	Polycode3DPhysics
	BulletDynamics
	BulletCollision
	LinearMath
	
	${background_LIBS}
	${collision_LIBS}
	${enemy_LIBS}
	${graphics_LIBS}
	${gui_LIBS}
	${missile_LIBS}
	${mission_LIBS}
	${space_LIBS}
)

set(src_SRCS ${src_SRCS} PARENT_SCOPE)
set(src_LIBS ${src_LIBS} PARENT_SCOPE)

