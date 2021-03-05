/*!
 * @file Complex class implementation
 */
#ifndef OWN_COMPLEX_HH
#define OWN_COMPLEX_HH

#include <own/complex.h>

#include <iostream>
#include <string>
#include <sstream>

namespace own {

template <typename T>
Complex<T>::Complex() : _real((T)0), _imag((T) 0) {
}

template <typename T>
Complex<T>::Complex(T real) : _real(real), _imag((T) 0) {
}

template <typename T>
Complex<T>::Complex(T real, T imag) : _real(real), _imag(imag) {
}

template <typename T>
Complex<T>::Complex(const Complex<T> &c): _real(c._real), _imag(c._imag) {
}

template <typename T>
Complex<T>::Complex(const std::string &s) {
    fromString(s);
}

template <typename T>
Complex<T>::~Complex() = default;

template <typename T>
bool Complex<T>::fromString(const std::string &s) {
    if (s.length() < 4 || s[s.length()-1] != 'i') { // min len: n+mi
        // std::cerr << "Can't read complex" << std::endl;
        return false;
    }
    T real = _real, imag = _imag;
    for (int i = 1; i < s.length(); i++) {
        if (s[i] == '-' || s[i] == '+') {
            std::stringstream ss(s.substr(0, i));
            ss >> real;
            if (ss.fail()) {
                //std::cerr << "Can't read complex real part" << std::endl;
                return false;
            }
            ss.str(s.substr(i, s.length()-i-1)); // With sign, without 'i'
            ss.clear();
            ss >> imag;
            if (ss.fail()) {
                //std::cerr << "Can't read complex imaginary part" << std::endl;
                return false;
            }
            break;
        }
    }
    _real = real;
    _imag = imag;
    return true;
}

template <typename T>
T Complex<T>::real() {
    return _real;
}

template <typename T>
T Complex<T>::imag() {
    return _imag;
}

template <typename T>
void Complex<T>::real(T real) {
    _real = real;
}

template <typename T>
void Complex<T>::imag(T imag) {
    _imag = imag;
}

template <typename T>
std::ostream& operator << (std::ostream &out, const Complex<T> &c) {
    out << c._real;
    if (c._imag >= (T) 0) {
        out << "+" << std::abs(c._imag);
    } else {
        out << "-" << std::abs(- c._imag);
    }
    out << "i";
    return out;
}

template <typename T>
std::istream& operator >> (std::istream &in, Complex<T> &c) {
    std::string s;
    in >> s;
    c.fromString(s);
    return in;
}

template <typename T>
Complex<T>& Complex<T>::operator = (const Complex<T> &c) {
    _real = c._real;
    _imag = c._imag;
    return *this;
}

template <typename T>
Complex<T> operator + (const Complex<T> &c) {
    return Complex<T>(c._real, c._imag);
}

template <typename T>
Complex<T> operator - (const Complex<T> &c) {
    return Complex<T>(- c._real, - c._imag);
}

template <typename T>
Complex<T> operator + (const Complex<T> &c1, const Complex<T> &c2) {
    return Complex<T>(c1._real + c2._real, c1._imag + c2._imag);
}

template <typename T>
Complex<T> operator - (const Complex<T> &c1, const Complex<T> &c2) {
    return Complex<T>(c1._real - c2._real, c1._imag - c2._imag);
}

template <typename T>
Complex<T> operator += (Complex<T> &c1, const Complex<T> &c2) {
    return Complex<T>(c1._real = c1._real + c2._real,
                      c1._imag = c1._imag + c2._imag);
}

template <typename T>
Complex<T> operator -= (Complex<T> &c1, const Complex<T> &c2) {
    return Complex<T>(c1._real = c1._real - c2._real,
                      c1._imag = c1._imag - c2._imag);
}

template <typename T>
Complex<T> operator * (const Complex<T> &c1, const Complex<T> &c2) {
    return Complex<T>(c1._real * c2._real - c1._imag * c2._imag,
                      c1._imag * c2._real + c1._real * c2._imag);
}

template <typename T>
Complex<T> operator / (const Complex<T> &c1, const Complex<T> &c2) {
    return Complex<T>((c1._real * c2._real + c1._imag * c2._imag)/(c2._real*c2._real + c2._imag*c2._imag),
                      (c2._real * c1._imag - c1._real * c2._imag)/(c2._real*c2._real + c2._imag*c2._imag));
}

template <typename T>
Complex<T> operator *= (Complex<T> &c1, const Complex<T> &c2) {
    T real = c1._real * c2._real - c1._imag * c2._imag;
    T imag = c1._imag * c2._real + c1._real * c2._imag;
    return Complex<T>(c1._real = real, c1._imag = imag);
}

template <typename T>
Complex<T> operator /= (Complex<T> &c1, const Complex<T> &c2) {
    T real = (c1._real * c2._real + c1._imag * c2._imag)/(c2._real * c2._real + c2._imag * c2._imag);
    T imag = (c2._real * c1._imag - c1._real * c2._imag)/(c2._real * c2._real + c2._imag * c2._imag);
    return Complex<T>(c1._real = real, c1._imag = imag);
}

template <typename T>
bool operator == (const Complex<T> &c1, const Complex<T> &c2) {
    return (c1._real == c2._real && c1._imag == c2._imag);
}

template <typename T>
bool operator != (const Complex<T> &c1, const Complex<T> &c2) {
    return !(c1 == c2);
}

template <typename T>
Complex<T>::operator bool() const noexcept {
    return !(_real == (T)0 && _imag == (T)0);
}

} //namespace own

#endif //OWN_COMPLEX_HH
