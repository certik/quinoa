//******************************************************************************
/*!
  \file      src/Parser/Parser.h
  \author    J. Bakosi
  \date      Mon 21 Jan 2013 09:14:37 PM MST
  \copyright Copyright 2005-2012, Jozsef Bakosi, All rights reserved.
  \brief     Parser base
  \details   Parser base
*/
//******************************************************************************
#ifndef Parser_h
#define Parser_h

#include <fstream>

#include <boost/spirit/include/lex_lexertl.hpp>

using namespace std;

namespace Quinoa {

//! Parser base
class Parser {

  public:
    //! Constructor
    Parser(const string& filename);

    //! Destructor
    virtual ~Parser();

  private:
    //! Don't permit copy constructor
    Parser(const Parser&) = delete;
    //! Don't permit copy assigment
    Parser& operator=(const Parser&) = delete;
    //! Don't permit move constructor
    Parser(Parser&&) = delete;
    //! Don't permit move assigment
    Parser& operator=(Parser&&) = delete;

    const string m_filename;            //!< Name of file to parse
    ifstream m_q;                       //!< Q (control) file input stream

    // Include token IDs
    #include <Parser.def.h>

//     template <typename Lexer>
//     struct word_count_tokens : lex::lexer<Lexer> {
//       word_count_tokens() {
//           // define tokens (the regular expression to match and the corresponding
//           // token id) and add them to the lexer
//           this->self.add
//             ("[^ \t\n]+", ID_WORD) // words (anything except ' ', '\t' or '\n')
//             ("\n", ID_EOL)         // newline characters
//             (".", ID_CHAR)         // anything else is a plain character
//           ;
//       }
//     };

};

} // namespace Quinoa

#endif // Parser_h