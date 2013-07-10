%namespace tbd
%class-name ConsoleLexer
%lex-source "ConsoleLexer.cpp"

%x TEXT COMMENT MULTICOMMENT

%%

[[:space:]]+ // ignoring whitespaces

"regene"	return ConsoleParser::REGENE;
"summon"	return ConsoleParser::SUMMON;
"remove"	return ConsoleParser::REMOVE;
"ship"		return ConsoleParser::SHIP;
"all"		return ConsoleParser::ALL;
"load"		return ConsoleParser::LOAD;
"clear"		return ConsoleParser::CLEAR;

"="	return ConsoleParser::EQUAL;
";"	return ConsoleParser::SEMICOLON;
"#" return ConsoleParser::SHARP;

"{"	return ConsoleParser::LBRACE;
"}" return ConsoleParser::RBRACE;

"if"   return ConsoleParser::IF;
"else" return ConsoleParser::ELSE;

[0-9]+								return ConsoleParser::INT;
[[:alpha:]][[:alpha:][:digit:]]*	return ConsoleParser::ID;

"\""		{ more(); begin(StartCondition__::TEXT); }
<TEXT>"\""	{ begin(StartCondition__::INITIAL); return ConsoleParser::TEXT; }
<TEXT>.		{ more(); }

"//" 				{ begin(StartCondition__::COMMENT); }
<COMMENT>\n			{ begin(StartCondition__::INITIAL); }
<COMMENT>. 			{ }

"/*"				{ begin(StartCondition__::MULTICOMMENT); }
<MULTICOMMENT>"*/"	{ begin(StartCondition__::INITIAL); }
<MULTICOMMENT>.		{ }

. return ConsoleParser::CHAR;
