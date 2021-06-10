/*!
 * @file Polynomial class implementation
 */
#ifndef OWN_POLYNOMIAL_HH
#define OWN_POLYNOMIAL_HH

#include <own/polynomial.h>

#include <iostream>
#include <initializer_list>

namespace own {

template <typename T>
Polynomial<T>::Polynomial(unsigned int _degree): degree(_degree), excess(0) {
    c = new T[degree+1];
    memset(c, 0, (degree+1)*sizeof(T));
}

template <typename T>
Polynomial<T>::Polynomial(const std::initializer_list<T> &list): Polynomial( list.size()-1 ) {
    int i = degree;
    typename std::initializer_list<T>::iterator it;
    for (it = list.begin(); it != list.end(); ++it) {
        c[i--] = *it;
    }
}

template <typename T>
T Polynomial<T>::getExcess() const {
    return excess;
}

template <typename T>
void Polynomial<T>::clearExcess() {
    excess = 0;
}

template <typename T>
T Polynomial<T>::calculate(T x) {
    T result = (T) 0;
    for (int i = degree; i >= 0; i--) {
        result *= x;
        result += c[i];
    }
    return result;
}

template <typename T>
T Polynomial<T>::derivative(T x, T dx) {
    return (calculate(x+dx) - calculate(x-dx)) / 2 / dx;
}

template <typename T>
void Polynomial<T>::show() const {
    std::cout << c[degree] << "*x^" << degree; 
    for (int i = degree-1; i >= 0; i--) {
        if (c[i] >= 0) {
            std::cout << "+";
        }
        std::cout << c[i] << "*x^" << i;
    }
    if (excess > 0) {
        std::cout << " (excess " << excess << ")";
    }
    std::cout << std::endl;
}

template <typename T>
std::istream& operator >> (std::istream &in, Polynomial<T> &p) {
    for (int i = p.degree; i >= 0; i++) {
        in >> p.c[i];
    }
    return in;
}

template <typename T>
std::ostream& operator << (std::ostream &out, const Polynomial<T> &p) {
    for (int i = p.degree; i >= 0; i++) {
        out << p.c[i];
    }
    return out;
}

template <typename T>
bool operator == (const Polynomial<T> &a, const Polynomial<T> &b) {
    if (a.degree != b.degree) {
        std::cout <<a.degree<<std::endl;
        return false;
    }

    for (int i = 0; i <= a.degree; i++) {
        if (a.c[i] != b.c[i]) {
            return false;
        }
    }
    return true;
}

} //namespace own

#endif //OWN_POLYNOMIAL_HH
