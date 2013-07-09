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

%type <INT> int value condition
%type <TEXT> id text

%%

InitialState: | CommandList;
CommandList:
	CommandList Command { this->registerCommand(); }
|
	Command { this->registerCommand(); }
;
Command:
	REGENE target { this->registerType(ConsoleCommandType::REGENE); }
|
	SUMMON target { this->registerType(ConsoleCommandType::SUMMON); }
|
	REMOVE target { this->registerType(ConsoleCommandType::REMOVE); }
|
	LOAD text { this->registerType(ConsoleCommandType::LOAD); }
|
	CLEAR { this->registerType(ConsoleCommandType::CLEAR); }
;

target:
	SHIP { currentTarget.name = "ship"; currentTarget.index = -1; }
|
	ALL { currentTarget.name = "all"; currentTarget.index = -2; }
|
	id {
		currentTarget.name = $1;
		currentTarget.index = 0;
	}
|
	id SHARP int {
		currentTarget.name = $1;
		currentTarget.index = $3;
	}
;

id: ID { $$ = d_scanner.matched(); };
text: TEXT { $$ = d_scanner.matched(); };
int: INT { $$ = std::stoll(d_scanner.matched()); };

