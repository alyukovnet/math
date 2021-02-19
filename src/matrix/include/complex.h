#ifndef COMPLEX_H
#define COMPLEX_H

#include <complex>
#include <iostream>

template <typename T>
class Complex: public std::complex<T> {
public:
    Complex();
    Complex(std::string);
    friend std::ostream& operator<<(std::ostream& os, const Complex<T>& c);
    friend std::istream& operator>>(std::istream& os, const Complex<T>& c);
};

#endif //COMPLEX_H
