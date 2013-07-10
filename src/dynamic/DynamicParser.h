// Generated by Bisonc++ V4.01.00 on Wed, 10 Jul 2013 14:02:10 +0200

#ifndef DynamicParser_h_included
#define DynamicParser_h_included

// $insert baseclass
#include "DynamicParserbase.h"
// $insert scanner.h
#include "DynamicLexer.h"
#include <string>

// $insert namespace-open
namespace tbd
{

#undef DynamicParser
class DynamicParser: public DynamicParserBase
{
    // $insert scannerobject
    DynamicLexer d_scanner;
        
    public:
        int parse();

    private:
        void error(char const *msg);    // called on (syntax) errors
		void error(std::string const& msg);
		void warning(std::string const& msg);
		void msg(std::string const& type, std::string const& msg);
        int lex();                      // returns the next token from the
                                        // lexical scanner. 
        void print();                   // use, e.g., d_token, d_loc

    // support functions for parse():
        void executeAction(int ruleNr);
        void errorRecovery();
        int lookup(bool recovery);
        void nextToken();
        void print__();

		void includeFile(std::string const&);
};

// $insert namespace-close
}

#endif
