
LEXER  := DynamicLexer.cpp
PARSER := DynamicParser.cpp
APP    := parser

SRCS   := main.cpp DynamicExtra.cpp $(LEXER) $(PARSER)
OBJS   := $(SRCS:.cpp=.o)

CXXFLAGS += -std=c++11 -Wall -pedantic

all: $(APP) $(LEXER) $(PARSER)

$(APP): $(OBJS)
	$(CXX) $^ -o $@

main.o: main.cpp $(LEXER) $(PARSER)

lexer.o: $(LEXER)

parse.o: $(PARSER)

$(LEXER): scanner.lex DynamicLexer.h DynamicLexer.ih
	flexc++ $<

$(PARSER): grammar.yy DynamicParser.h DynamicParser.ih
	bisonc++ $<

clean: parser.clean scanner.clean
	$(RM) *.o $(APP)

parser.clean:
	$(RM) $(PARSER) DynamicParserbase.h

scanner.clean:
	$(RM) $(LEXER) DynamicLexerbase.h

.PHONY: clean parser.clean scanner.clean

run: $(APP)
	./$(APP) < test.sopp
