%namespace tbd
%class-name DynamicParser
%parsefun-source DynamicParser.cpp

%scanner DynamicLexer.h
%scanner-token-function lexer.lex()

%token EQUAL SEMICOLON COLON COMMA SHARP
%token IF ELSE
%token LBRACE RBRACE LANGLE RANGLE
%token ID INT FLOAT CHAR TEXT

%token REGENE SUMMON REMOVE LOAD CLEAR
%token CORE WEAPON ENEMY
%token SHIP ALL

%polymorphic INT: long long int; FLOAT: long double; TEXT: std::string;

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
	FirstOrderId id FirstOrderGroup
;
SecondOrderElement: Command;

FirstOrderId: CORE | WEAPON | ENEMY;
FirstOrderGroup: LBRACE MemberDefList RBRACE;

MemberDefList: | MemberDefList MemberDef;
MemberDef:
	id COLON rValueList SEMICOLON
|
	FirstOrderId COLON rValueList SEMICOLON
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

rValueList: rValueList COMMA rValue | rValue;
rValue: id | text | int | float | tuple;

tuple: LANGLE rValueList RANGLE;

id: ID { $$ = d_scanner.matched(); };
text: TEXT { $$ = d_scanner.matched(); };
int: INT { $$ = std::stoll(d_scanner.matched()); };
float: FLOAT { $$ = std::stold(d_scanner.matched()); };

