
mklist(console_SRCS ${root}
	ConsoleLexer.cpp
	ConsoleParser.cpp
	ConsoleExtra.cpp
)

set(console_SRCS ${console_SRCS} PARENT_SCOPE)
set(console_LIBS ${console_LIBS} PARENT_SCOPE)
