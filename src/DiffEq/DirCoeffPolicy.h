//******************************************************************************
/*!
  \file      src/DiffEq/DirCoeffPolicy.h
  \author    J. Bakosi
  \date      Tue 09 Dec 2014 06:23:23 AM MST
  \copyright 2012-2014, Jozsef Bakosi.
  \brief     Dirichlet coefficients policies
  \details   Dirichlet coefficients policies
*/
//******************************************************************************
#ifndef DirCoeffPolicy_h
#define DirCoeffPolicy_h

#include <boost/mpl/vector.hpp>

#include <Types.h>
#include <Options/CoeffPolicy.h>

namespace walker {

//! Dirichlet constant coefficients policity: constants in time
struct DirCoeffConst {

  //! Constructor: default for accessing policy name, type, etc.
  DirCoeffConst() = default;
  //! Constructor: initialize coefficients
  DirCoeffConst( unsigned int ncomp,
                 const std::vector< tk::real >& b_,
                 const std::vector< tk::real >& S_,
                 const std::vector< tk::real >& k_,
                 std::vector< tk::real >& b,
                 std::vector< tk::real >& S,
                 std::vector< tk::real >& k )
  {
    b = b_;
    S = S_;
    k = k_;
    ErrChk( b.size() == ncomp, "Wrong number of Dirichlet SDE parameters 'b'");
    ErrChk( S.size() == ncomp, "Wrong number of Dirichlet SDE parameters 'S'");
    ErrChk( k.size() == ncomp, "Wrong number of Dirichlet SDE parameters 'k'");
  }

  std::string policy() const noexcept
  { return tk::ctr::CoeffPolicy().name( tk::ctr::CoeffPolicyType::CONSTANT ); }

  tk::ctr::CoeffPolicyType type() const noexcept
  { return tk::ctr::CoeffPolicyType::CONSTANT; }

  //! Function call: no-op for constant coefficients
  void operator()( const tk::real&,
                   std::vector< tk::real >&,
                   std::vector< tk::real >&,
                   std::vector< tk::real >& ) {}
};

//! List of all Dirichlet's coefficients policies
using DirCoeffPolicies = boost::mpl::vector< DirCoeffConst >;

} // walker::

#endif // DirCoeffPolicy_h
