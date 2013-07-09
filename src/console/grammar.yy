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
	CommandList Command { this->recordCommand(); }
|
	Command { this->recordCommand(); }
;
Command:
	REGENE target { this->recordType(ConsoleCommandType::REGENE); }
|
	SUMMON target { this->recordType(ConsoleCommandType::SUMMON); }
|
	REMOVE target { this->recordType(ConsoleCommandType::REMOVE); }
|
	LOAD text { this->recordType(ConsoleCommandType::LOAD); }
|
	CLEAR { this->recordType(ConsoleCommandType::CLEAR); }
;

target:
	SHIP { this->recordTarget("ship", -1); }
|
	ALL { this->recordTarget("all", 2); }
|
	id { this->recordTarget($1, 0); }
|
	id SHARP int { this->recordTarget($1, $3); }
;

id: ID { $$ = d_scanner.matched(); };
text: TEXT { $$ = d_scanner.matched(); };
int: INT { $$ = std::stoll(d_scanner.matched()); };

