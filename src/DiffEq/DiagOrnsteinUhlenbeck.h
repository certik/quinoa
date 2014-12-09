//******************************************************************************
/*!
  \file      src/DiffEq/DiagOrnsteinUhlenbeck.h
  \author    J. Bakosi
  \date      Mon 08 Dec 2014 05:16:49 PM MST
  \copyright 2012-2014, Jozsef Bakosi.
  \brief     Diagonal Ornstein-Uhlenbeck SDE
  \details   Diagonal Ornstein-Uhlenbeck SDE.
*/
//******************************************************************************
#ifndef DiagOrnsteinUhlenbeck_h
#define DiagOrnsteinUhlenbeck_h

#include <cmath>

#include <InitPolicy.h>
#include <DiagOUCoeffPolicy.h>
#include <RNG.h>

namespace walker {

extern ctr::InputDeck g_inputdeck;
extern std::map< tk::ctr::RawRNGType, tk::RNG > g_rng;

//! Diagonal Ornstein-Uhlenbeck SDE used polymorphically with DiffEq
template< class Init, class Coefficients >
class DiagOrnsteinUhlenbeck {

  public:
    //! Constructor
    explicit DiagOrnsteinUhlenbeck( unsigned int c ) :
      m_ncomp( g_inputdeck.get< tag::component >().get< tag::diagou >()[c] ),
      m_offset(g_inputdeck.get< tag::component >().offset< tag::diagou >(c)),
      m_rng( g_rng.at( tk::ctr::raw(
        g_inputdeck.get< tag::param, tag::diagou, tag::rng >()[c] ) ) )
    {
      const auto& sigma =
        g_inputdeck.get< tag::param, tag::diagou, tag::sigma >();
      const auto& theta =
        g_inputdeck.get< tag::param, tag::diagou, tag::theta >();
      const auto& mu = g_inputdeck.get< tag::param, tag::diagou, tag::mu >();
      ErrChk( sigma.size() > c,
              "Indexing out of diagonal OU SDE parameters 'sigma'");
      ErrChk( theta.size() > c,
              "Indexing out of diagonal OU SDE parameters 'theta'");
      ErrChk( mu.size() > c,
              "Indexing out of diagonal OU SDE parameters 'mu'");
      // Use coefficients policy to initialize coefficients
      Coefficients( m_ncomp, sigma[c], theta[c], mu[c], m_sigma, m_theta, m_mu );
    }

    //! Set initial conditions
    void initialize( tk::ParProps& particles ) const { Init( { particles } ); }

    //! Advance particles
    void advance( tk::ParProps& particles, int stream, tk::real dt ) const {
      const auto npar = particles.npar();
      for (auto p=decltype(npar){0}; p<npar; ++p) {
        // Generate Gaussian random numbers with zero mean and unit variance
        tk::real dW[m_ncomp];
        m_rng.gaussian( stream, m_ncomp, dW );

        // Advance all m_ncomp scalars
        for (unsigned int i=0; i<m_ncomp; ++i) {
          tk::real& par = particles( p, i, m_offset );
          tk::real d = m_sigma[i] * m_sigma[i] * dt;
          d = (d > 0.0 ? std::sqrt(d) : 0.0);
          par += m_theta[i]*(m_mu[i] - par)*dt + d*dW[i];
        }
      }
    }

  private:
    const unsigned int m_ncomp;         //!< Number of components
    const int m_offset;                 //!< Offset SDE operates from
    const tk::RNG& m_rng;               //!< Random number generator
    std::vector< tk::real > m_sigma;    //!< Coefficients
    std::vector< tk::real > m_theta;
    std::vector< tk::real > m_mu;
};

} // walker::

#endif // DiagOrnsteinUhlenbeck_h
