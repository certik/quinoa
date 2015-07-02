## What is Quinoa?

Quinoa is a set of computational tools that enables research and numerical
analysis in fluid dynamics. At this time it is a test-bed to experiment with
various algorithms using fully asynchronous runtime systems.

## Organization

Currently, Quinoa consists of the following tools:
  * inciter - Solve a PDE on an unstructured mesh using overdecomposition
  * walker - Random walker for stochastic differential equations
  * rngtest - Random number generator test suite
  * unittest - Unit test suite
  * meshconv - Mesh file converter

## Rationale

  * Designed for the exascale era
  * Verified and proven to be correct
  * Optimized for performance, power, and reliability
  * Advanced computer science outsourced to experts
  * Using a language that can cope with complexity
  * Highly-valued programmer productivity
  * User and developer friendly
  * Well documented
  * Fun to work on

## License

Copyright (c) 2012-2015, Jozsef Bakosi
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

- Redistributions of source code must retain the above copyright notice, this
  list of conditions and the following disclaimer.

- Redistributions in binary form must reproduce the above copyright notice,
  this list of conditions and the following disclaimer in the documentation
  and/or other materials provided with the distribution.

- Neither the name of test nor the names of its
  contributors may be used to endorse or promote products derived from
  this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

## Authors

Jozsef Bakosi (jbakosi@lanl.gov)

## How to build

 1. Pick compilers

   ```
    $ CC=mpicc CXX=mpic++ FC=mpif90 F77=mpif77 F90=mpif90
   ```
   * Currently, MPI is required, use the OpenMPI wrappers
   * The underlying C++ compiler must support the C++11 standard

 2. Build the required third-party libraries (TPLs)

   ```
    $ cd <quinoa>/tpl; mkdir -p build; cd build
    $ cmake ..
    $ make
   ```
   * The CMAKE_INSTALL_PREFIX cmake variable defaults to
     <quinoa>/tpl/install/<compiler>, which is where the TPLs are installed

 3. Build Quinoa

   ```
    $ cd <quinoa>; mkdir build; cd build
    $ cmake ../src
    $ make
   ```
   * All executables will be in <quinoa>/build/Main.
   * The TPL_DIR cmake variable defaults to <quinoa>/tpl/install/<compiler>

## Where to go from here

 1. Run the unit tests

   ```
    $ <quinoa>/build
    $ Main/charmrun +p4 Main/unittest
   ```

 2. Build the documentation

   ```
    $ cd <quinoa>/build
    $ make doc
   ```
   * Point a web browser to <quinoa>/build/doc/html/index.html

 3. Build the code coverage report

   ```
    $ cd <quinoa>/build
    $ make coverage
   ```
   * Point a web browser to <quinoa>/build/unittest_coverage/index.html

 4. Check out some examples

   * Point a web browser to <quinoa>/build/doc/html/examples.html