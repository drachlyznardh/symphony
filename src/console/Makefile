
LEXER  := ConsoleLexer.cpp
PARSER := ConsoleParser.cpp
APP    := parser

SRCS   := main.cpp $(LEXER) $(PARSER)
OBJS   := $(SRCS:.cpp=.o)

CXXFLAGS += -std=c++11 -Wall -pedantic

$(APP): $(OBJS)
	$(CXX) $^ -o $@

main.o: main.cpp $(LEXER) $(PARSER)

lexer.o: $(LEXER)

parse.o: $(PARSER)

$(LEXER): scanner.lex
	flexc++ $<

$(PARSER): grammar.yy
	bisonc++ $<

clean: parser.clean scanner.clean
	$(RM) *.o $(APP)

parser.clean:
	$(RM) $(PARSER) ConsoleParserbase.h

scanner.clean:
	$(RM) $(LEXER) ConsoleLexerbase.h

.PHONY: clean parser.clean scanner.clean

run: $(APP)
	./$(APP) < /tmp/test
