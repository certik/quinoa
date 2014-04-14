//******************************************************************************
/*!
  \file      src/RNGTest/TestU01Util.h
  \author    J. Bakosi
  \date      Wed 09 Apr 2014 04:09:22 PM MDT
  \copyright Copyright 2005-2012, Jozsef Bakosi, All rights reserved.
  \brief     Interfacing the TestU01 random number generator test suite
  \details   Interfacing the TestU01 random number generator test suite
*/
//******************************************************************************
#ifndef TestU01Wrap_h
#define TestU01Wrap_h

#include <Battery.h>

namespace rngtest {

//! Custom deleter binding a raw TestU01 pointer to its TestU01 deleter
template< typename RawPtr, void (*Deleter)(RawPtr *) >
struct Eraser {
  void operator()( RawPtr* ptr ) {
    Deleter( ptr );
  }
};

//! TestU01 pointer type with a custom deleter
template< class Ptr, void (*Deleter)(Ptr *) >
using TestU01Ptr = std::unique_ptr< Ptr, Eraser< Ptr, Deleter > >;

} // rngtest::

#endif // TestU01Wrap_h