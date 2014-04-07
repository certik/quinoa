//******************************************************************************
/*!
  \file      src/Control/Gmsh2Exo/CmdLine/Grammar.h
  \author    J. Bakosi
  \date      Mon Mar 24 10:29:37 2014
  \copyright Copyright 2005-2012, Jozsef Bakosi, All rights reserved.
  \brief     Gmsh2Exo's command line grammar definition
  \details   Grammar definition for parsing the command line. We use the Parsing
  Expression Grammar Template Library (PEGTL) to create the grammar and the
  associated parser. Credit goes to Colin Hirsch (pegtl@cohi.at) for PEGTL. Word
  of advice: read from the bottom up.
*/
//******************************************************************************
#ifndef Gmsh2ExoCmdLineGrammar_h
#define Gmsh2ExoCmdLineGrammar_h

#include <Macro.h>
#include <Exception.h>
#include <Grammar.h>
#include <PEGTLParsed.h>
#include <Gmsh2Exo/CmdLine/Keywords.h>

namespace gmsh2exo {
//! Grammar definition: state, actions, grammar
namespace cmd {

  //! PEGTLParsed type specialized to Gmsh2Exo's command line parser
  using PEGTLCmdLine =
    quinoa::ctr::PEGTLParsed< ctr::CmdLine,
                              pegtl::string_input< ctr::Location > >;

  // Gmsh2Exo's CmdLine state

  //! Everything is stored in Stack during parsing
  using Stack = PEGTLCmdLine;

  // Gmsh2Exo's CmdLine actions

  // Gmsh2Exo's CmdLine grammar

  //! io parameter
  template< typename keyword, typename io_tag >
  struct io :
         tk::grm::process_cmd< Stack,
                               keyword,
                               tk::grm::Store< Stack, tag::io, io_tag > > {};

  //! command line keywords
  struct keywords :
         pegtl::sor< io< kw::input, tag::input >,
                     io< kw::output, tag::output > > {};

  //! entry point: parse keywords and until end of string
  struct read_string :
         tk::grm::read_string< Stack, keywords > {};

} // cmd::
} // gmsh2exo::

#endif // Gmsh2ExoCmdLineGrammar_h