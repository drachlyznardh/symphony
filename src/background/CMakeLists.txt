
mklist(background_SRCS ${root}
	Background.cpp
	StarDrawer.cpp
	StarEntity.cpp
	StarredBackground.cpp
)

set(background_SRCS ${background_SRCS} PARENT_SCOPE)
set(background_LIBS ${background_LIBS} PARENT_SCOPE)
