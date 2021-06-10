/*!
 * @file Binomial class implementation
 */
#ifndef OWN_BINOMIAL_HH
#define OWN_BINOMIAL_HH

#include <own/binomial.h>

#include <iostream>
#include <initializer_list>

namespace own {

template <typename T>
Binomial<T>::Binomial(T e): Polynomial<T>{1, -e} {}

template <typename T>
Polynomial<T> operator / (const Polynomial<T> &a, const Binomial<T> &b) {
    Polynomial<T> result(a.degree-1);

    result.c[a.degree - 1] = a.c[a.degree];
    for (int i = a.degree - 2; i >= 0; i--) {
        result.c[i] = a.c[i+1] - b.c[0] * result.c[i+1];
    }
    result.excess = a.c[0] - b.c[0] * result.c[0];
    
    return result;
}

template <typename T>
Polynomial<T> operator * (const Polynomial<T> &a, const Binomial<T> &b) {
    Polynomial<T> result(a.degree+1);

    for (int i = 0; i <= a.degree; i++) {
        for (int j = 0; j <= b.degree; j++) {
            result.c[i+j] += a.c[i]*b.c[j];
        }
    }
    result.c[0] += a.excess;
    
    return result;
}

} //namespace own

#endif //OWN_BINOMIAL_HH
