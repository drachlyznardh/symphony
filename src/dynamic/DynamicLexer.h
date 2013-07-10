// Generated by Flexc++ V0.98.00 on Wed, 10 Jul 2013 14:02:10 +0200

#ifndef DynamicLexer_H_INCLUDED_
#define DynamicLexer_H_INCLUDED_

// $insert baseclass_h
#include "DynamicLexerbase.h"

// $insert namespace-open
namespace tbd
{

// $insert classHead
class DynamicLexer: public DynamicLexerBase
{
    public:
        explicit DynamicLexer(std::istream &in = std::cin,
                                std::ostream &out = std::cout);

        DynamicLexer(std::string const &infile, std::string const &outfile);
        
        // $insert lexFunctionDecl
        int lex();

    private:
        int lex__();
        int executeAction__(size_t ruleNr);

        void print();
        void preCode();     // re-implement this function for code that must 
                            // be exec'ed before the patternmatching starts
};

// $insert scannerConstructors
inline DynamicLexer::DynamicLexer(std::istream &in, std::ostream &out)
:
    DynamicLexerBase(in, out)
{}

inline DynamicLexer::DynamicLexer(std::string const &infile, std::string const &outfile)
:
    DynamicLexerBase(infile, outfile)
{}

// $insert inlineLexFunction
inline int DynamicLexer::lex()
{
    return lex__();
}

inline void DynamicLexer::preCode() 
{
    // optionally replace by your own code
}

inline void DynamicLexer::print() 
{
    print__();
}

// $insert namespace-close
}

#endif // DynamicLexer_H_INCLUDED_
