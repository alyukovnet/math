/*!
 * @file
 * @brief Polynomial class header file
 */
#ifndef OWN_POLYNOMIAL_H
#define OWN_POLYNOMIAL_H

#include <initializer_list>
#include <iostream>

namespace own {

/*!
 * @brief Polynomial
 * @tparam T Coefficients type
 */
template <typename T>
class Polynomial {
public:
    unsigned int degree;  // Degree
    T *c;        // Coefficients
    T excess;    // Excess after division

public:
    /*!
     * Null polynomial from degree
     * @param[in] _degree Degree
     */
    Polynomial(unsigned int _degree);
    
    /*!
     * Polynomial from coefficients
     * @param[in] _c List of coefficients
     */
    Polynomial(const std::initializer_list<T> &_c);

    /*!
     * Get excess of result after division
     */
    T getExcess() const;

    /*!
     * Clear excess of result after division
     */
    void clearExcess();

    /*!
     * Calculate
     * @param[in] x Variable (x) value
     */
    T calculate(T x);

    /*!
     * Derivative
     * @param[in] x  Variable (x) value
     * @param[in] dx dX
     */
    T derivative(T x, T dx);

    /*!
     * Show polynomial (ax^n+bx^(n-1)...+z) and degree if existed 
     */
    void show() const;

    /*!
     * Polynomial comparison
     * @param[in] a Polynomial of degree D
     * @param[in] b Polynomial of degree D
     * @result a = b
     */
    template <typename U>
    friend bool operator == (const Polynomial<U> &a, const Polynomial<U> &b);

    /*!
     * Input from stream (separated by a gap)
     * @param[in] in Output stream
     * @param[out] c Polynomial
     * @return Output stream
     */
    friend std::ostream& operator >> (std::ostream &in, Polynomial &p);

    /*!
     * Output to stream (separated by a gap)
     * @param[in] out Output stream
     * @param[out] c Polynomial
     * @return Output stream
     */
    friend std::ostream& operator << (std::ostream &out, const Polynomial &p);

};

} //namespace own

// Polynomial class implementation
#include "../../src/polynomial.hh"

#endif //OWN_POLYNOMIAL_H
