%namespace tbd
%class-name DynamicLexer
%lex-source "DynamicLexer.cpp"

%x TEXT COMMENT MULTICOMMENT

%%

[[:space:]]+ // ignoring whitespaces

"regene"	return DynamicParser::REGENE;
"summon"	return DynamicParser::SUMMON;
"remove"	return DynamicParser::REMOVE;
"ship"		return DynamicParser::SHIP;
"all"		return DynamicParser::ALL;
"load"		return DynamicParser::LOAD;
"clear"		return DynamicParser::CLEAR;

"="	return DynamicParser::EQUAL;
";"	return DynamicParser::SEMICOLON;
"#" return DynamicParser::SHARP;

"{"	return DynamicParser::LBRACE;
"}" return DynamicParser::RBRACE;

"if"   return DynamicParser::IF;
"else" return DynamicParser::ELSE;

[0-9]+								return DynamicParser::INT;
[[:alpha:]][[:alpha:][:digit:]]*	return DynamicParser::ID;

"\""		{ more(); begin(StartCondition__::TEXT); }
<TEXT>"\""	{ begin(StartCondition__::INITIAL); return DynamicParser::TEXT; }
<TEXT>.		{ more(); }

"//" 				{ begin(StartCondition__::COMMENT); }
<COMMENT>\n			{ begin(StartCondition__::INITIAL); }
<COMMENT>. 			{ }

"/*"				{ begin(StartCondition__::MULTICOMMENT); }
<MULTICOMMENT>"*/"	{ begin(StartCondition__::INITIAL); }
<MULTICOMMENT>.		{ }

. return DynamicParser::CHAR;

