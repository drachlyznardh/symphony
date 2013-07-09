%namespace tbd
%class-name ConsoleParser
%parsefun-source ConsoleParser.cpp

%scanner ConsoleLexer.h
%scanner-token-function lexer.lex()

%token EQUAL SEMICOLON
%token IF ELSE
%token LBRACE RBRACE
%token ID INT CHAR TEXT

%token REGENE SUMMON
%token SHIP ALL

%polymorphic INT: int; TEXT: std::string;

%type <INT> int value condition
%type <TEXT> id

%%

InitialState: | CommandList;
CommandList: CommandList Command | Command;
Command:
	regene ship { std::cout << "[Regene ship]" << std::endl; }
|
	summon target { std::cout << "[Summoning target]" << std::endl; }
;

regene: REGENE;
ship: SHIP;
summon: SUMMON;
target: TARGET;

