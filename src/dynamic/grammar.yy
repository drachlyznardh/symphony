%namespace tbd
%class-name DynamicParser
%parsefun-source DynamicParser.cpp

%scanner DynamicLexer.h
%scanner-token-function lexer.lex()

%token EQUAL SEMICOLON SHARP
%token IF ELSE
%token LBRACE RBRACE
%token ID INT CHAR TEXT

%token INCLUDE
%token REGENE SUMMON REMOVE LOAD CLEAR
%token SHIP ALL

%polymorphic INT: int; TEXT: std::string;

%type <INT> int value condition
%type <TEXT> id text

%%

TranslationUnit: | FirstOrderList;
FirstOrderList:
	FirstOrderElement FirstOrderList
|
	SecondOrderList
;
SecondOrderList: SecondOrderList SecondOrderElement | SecondOrderElement;

FirstOrderElement:
	INCLUDE text
	{
		std::cout << "Including [" << $2 << "]" << std::endl;
		//this->includeFile($2);
	}
;
SecondOrderElement: Command;

InitialState: | CommandList;
CommandList:
	CommandList Command
|
	Command
;
Command:
	REGENE target
|
	SUMMON target
|
	REMOVE target
|
	LOAD text
|
	CLEAR
;

target:
	SHIP
|
	ALL
|
	id
|
	id SHARP int
;

id: ID { $$ = d_scanner.matched(); };
text: TEXT { $$ = d_scanner.matched(); };
int: INT { $$ = std::stoll(d_scanner.matched()); };

