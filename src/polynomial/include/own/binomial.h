/*!
 * @file
 * @brief Binomial class header file
 */
#ifndef OWN_BINOMIAL_H
#define OWN_BINOMIAL_H

#include <own/polynomial.h>
#include <iostream>

namespace own {

/*!
 * @brief Binomial
 * @tparam T Coefficient type
 */
template <typename T>
class Binomial: public Polynomial<T> {
public:
    /*!
     * Binomial from coefficient
     * @param[in] e Coefficient in (x - e)
     */
    Binomial(T e);

    /*!
     * Polynomial division by binary polynomial
     * @param[in] a Polynomial of degree D
     * @param[in] b Binomial
     * @result Polynomial of degree D-1
     */
    template <typename U>
    friend Polynomial<U> operator / (const Polynomial<U> &a, const Binomial<U> &b);

    /*!
     * Polynomial multiplication by binomial
     * @param[in] a Polynomial of degree D
     * @param[in] b Binomial
     * @result Polynomial of degree D+1
     */
    template <typename U>
    friend Polynomial<U> operator * (const Polynomial<U> &a, const Binomial<U> &b);

};

} //namespace own

// Binomial class implementation
#include "../../src/binomial.hh"

#endif //OWN_BINOMIAL_H
