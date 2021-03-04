/*!
 * @file Matrix class
 */
#include "own/matrix.h"
#include "matrix.hh"

#include "own/complex.h"

namespace own {

// todo: Class implementation add (now doesn't work I think)
template class Matrix<Complex<float>>;
template class Matrix<Complex<double>>;
template class Matrix<Complex<long double>>;

} //namespace own
