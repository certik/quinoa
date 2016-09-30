// *****************************************************************************
/*!
  \file      src/NoWarning/H5Part.h
  \author    J. Bakosi
  \date      Fri 30 Sep 2016 12:40:14 PM MDT
  \copyright 2012-2015, Jozsef Bakosi, 2016, Los Alamos National Security, LLC.
  \brief     Include H5Part.h with turning off specific compiler warnings
*/
// *****************************************************************************
#ifndef nowarning_H5Part_h
#define nowarning_H5Part_h

#if defined(__clang__)
  #pragma clang diagnostic push
  #pragma clang diagnostic ignored "-Wreserved-id-macro"
  #pragma clang diagnostic ignored "-Wold-style-cast"
  #pragma clang diagnostic ignored "-Wsign-conversion"
  #pragma clang diagnostic ignored "-Wdeprecated"
  #pragma clang diagnostic ignored "-Wcast-align"
#elif defined(__GNUC__)
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wlong-long"
#endif

#define PARALLEL_IO
#include <H5Part.h>
#undef PARALLEL_IO

#if defined(__clang__)
  #pragma clang diagnostic pop
#elif defined(__GNUC__)
  #pragma GCC diagnostic pop
#endif

#endif // nowarning_H5Part_h
