%namespace tbd
%class-name DynamicLexer
%lex-source "DynamicLexer.cpp"

%x INCLUDE ANGLE_INCLUDE QUOTE_INCLUDE
%x TEXT COMMENT MULTICOMMENT

%%

[[:space:]]+ // ignoring whitespaces

// Include directives
"include" { begin(StartCondition__::INCLUDE); //return DynamicParser::INCLUDE;
}
<INCLUDE>"<" { more(); begin(StartCondition__::ANGLE_INCLUDE); }
<INCLUDE>"\"" { more(); begin(StartCondition__::QUOTE_INCLUDE); }
<INCLUDE>[[:space:]] {}
<ANGLE_INCLUDE>">" {
	pushStream(matched().substr(1, matched().size()-2));
	begin(StartCondition__::INITIAL);
	//return DynamicParser::TEXT;
}
<QUOTE_INCLUDE>"\"" {
	pushStream(matched().substr(1, matched().size()-2));
	begin(StartCondition__::INITIAL);
	//return DynamicParser::TEXT;
}
<ANGLE_INCLUDE,QUOTE_INCLUDE>. { more(); }

// List of keywords
"core"		return DynamicParser::CORE;
"weapon"	return DynamicParser::WEAPON;
"enemy"		return DynamicParser::ENEMY;

"regene"	return DynamicParser::REGENE;
"summon"	return DynamicParser::SUMMON;
"remove"	return DynamicParser::REMOVE;
"ship"		return DynamicParser::SHIP;
"all"		return DynamicParser::ALL;
"load"		return DynamicParser::LOAD;
"clear"		return DynamicParser::CLEAR;

// List of symbols
"="	return DynamicParser::EQUAL;
":"	return DynamicParser::COLON;
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

