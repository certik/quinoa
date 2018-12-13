// *****************************************************************************
/*!
  \file      src/Control/Tags.h
  \copyright 2012-2015, J. Bakosi, 2016-2018, Los Alamos National Security, LLC.
  \brief     Tags
  \details   Tags are unique types, used for metaprogramming.
*/
// *****************************************************************************
#ifndef Tags_h
#define Tags_h

//! Tags used as unique-type labels for compile-time code-generation
namespace tag {

struct io {};
struct quiescence {};
struct input {};
struct output {};
struct diag {};
struct seed {};
struct uniform_method {};
struct gaussian_method {};
struct gaussianmv_method {};
struct gaussian {};
struct jointgaussian {};
struct beta_method {};
struct gamma_method {};
struct rng {};
struct xminus {};
struct xplus {};
struct yminus {};
struct yplus {};
struct zminus {};
struct zplus {};
struct rngmkl {};
struct rngsse {};
struct rng123 {};
struct seqlen {};
struct verbose {};
struct benchmark {};
struct lboff {};
struct feedback {};
struct reorder {};
struct error {};
struct pdf {};
struct ordpdf {};
struct cenpdf {};
struct nchare {};
struct bounds {};
struct filetype {};
struct pdfpolicy {};
struct pdfctr {};
struct pdfnames {};
struct flformat {};
struct prec {};
struct ordinary {};
struct central {};
struct binsize {};
struct extent {};
struct dirichlet {};
struct mixdirichlet {};
struct gendir {};
struct wrightfisher {};
struct p0 {};
struct beta {};
struct betax {};
struct betay {};
struct betaz {};
struct r0 {};
struct ce {};
struct numfracbeta {};
struct massfracbeta {};
struct mixnumfracbeta {};
struct mixmassfracbeta {};
struct alpha {};
struct gamma {};
struct spike {};
struct betapdf {};
struct hydrotimescales {};
struct hydroproductions {};
struct diffeq {};
struct pde {};
struct amr {};
struct t0ref {};
struct dtref {};
struct dtfreq {};
struct partitioner {};
struct scheme {};
struct initpolicy {};
struct coeffpolicy {};
struct montecarlo {};
struct nstep {};
struct term {};
struct t0 {};
struct dt {};
struct cfl {};
struct fct {};
struct ctau {};
struct npar {};
struct refined {};
struct matched {};
struct part {};
struct centroid {};
struct ncomp {};
struct nmat {};
struct tty {};
struct dump {};
struct plot {};
struct glob {};
struct control {};
struct stat {};
struct field {};
struct atwood {};
struct b {};
struct S {};
struct kappa {};
struct bprime {};
struct kappaprime {};
struct rho2 {};
struct rcomma {};
struct r {};
struct c {};
struct c0 {};
struct c1 {};
struct c2 {};
struct c3 {};
struct c4 {};
struct com1 {};
struct com2 {};
struct lambda {};
struct sigmasq {};
struct theta {};
struct mu {};
struct mean {};
struct cov {};
struct timescale {};
struct depvar {};
struct refvar {};
struct virtualization {};
struct omega {};
struct slm {};
struct glm {};
struct diagou {};
struct ou {};
struct skewnormal {};
struct position {};
struct dissipation {};
struct velocity {};
struct variant {};
struct mass {};
struct hydro {};
struct energy {};
struct mix {};
struct frequency {};
struct mixrate {};
struct title {};
struct selected {};
struct discr {};
struct component {};
struct interval {};
struct cmd {};
struct param {};
struct init {};
struct solve {};
struct chare {};
struct battery {};
struct generator {};
struct help {};
struct helpctr {};
struct helpkw {};
struct cmdinfo {};
struct ctrinfo {};
struct group {};
struct esup {};
struct psup {};
struct gid {};
struct transport {};
struct advection {};
struct compflow {};
struct multimat_compflow {};
struct problem {};
struct physics {};
struct diffusivity {};
struct u0 {};
struct bcdir {};
struct bcsym {};
struct bcinlet {};
struct bcoutlet {};
struct bcextrapolate {};
struct material {};
struct id {};
struct position_id {};
struct velocity_id {};
struct dissipation_id {};
struct mixmassfracbeta_id {};
struct edge {};
struct cv {};
struct k {};
struct com {};
struct coord {};
struct refinserted {};
struct discinserted {};
struct disccreated {};
struct workinserted {};
struct distributed {};
struct flattened {};
struct load {};
struct bcast {};
struct elem {};
struct avecost {};
struct stdcost {};
struct flux {};
struct ndof{};
struct limiter {};
struct cweight {};
struct update {};
struct ch {};
struct pe {};
struct it {};
struct fn {};
struct time {};

struct BirthdaySpacings {};
struct Collision {};
struct RandomWalk1 {};
struct Gap {};
struct SimplePoker {};
struct CouponCollector {};
struct MaxOft {};
struct WeightDistrib {};
struct MatrixRank {};
struct HammingIndep {};
struct SerialOver {};
struct CollisionOver {};
struct ClosePairs {};
struct ClosePairsBitMatch {};
struct Run {};
struct Permutation {};
struct CollisionPermut {};
struct SampleProd {};
struct SampleMean {};
struct SampleCorr {};
struct AppearanceSpacings {};
struct SumCollector {};
struct Savir2 {};
struct GCD {};
struct LinearComp {};
struct LempelZiv {};
struct Fourier3 {};
struct LongestHeadRun {};
struct PeriodsInStrings {};
struct HammingWeight2 {};
struct HammingCorr {};
struct StringRun {};
struct AutoCorr {};

} // tag::

#endif // Tags_h
