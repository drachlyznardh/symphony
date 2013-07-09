%namespace tbd
%class-name ConsoleParser
%parsefun-source ConsoleParser.cpp

%scanner ConsoleLexer.h
%scanner-token-function lexer.lex()

%token EQUAL SEMICOLON SHARP
%token IF ELSE
%token LBRACE RBRACE
%token ID INT CHAR TEXT

%token REGENE SUMMON REMOVE LOAD CLEAR
%token SHIP ALL

%polymorphic INT: int; TEXT: std::string;

%type <INT> INT value condition
%type <TEXT> ID TEXT

%%

InitialState: | CommandList;
CommandList: CommandList Command | Command;
Command:
	REGENE target { std::cout << "[Regene]" << std::endl; }
|
	SUMMON target { std::cout << "[Summoning]" << std::endl; }
|
	REMOVE target { std::cout << "[Removing]" << std::endl; }
|
	LOAD TEXT { std::cout << "[Load]" << std::endl; }
|
	CLEAR { std::cout << "[Clear]" << std::endl; }
;

target:
	SHIP
|
	ALL
|
	ID
|
	ID SHARP INT
;

