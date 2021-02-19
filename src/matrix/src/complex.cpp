#include "../include/complex.h"

#include <iostream>
#include <string>
#include <sstream>

template <typename T>
Complex<T>::Complex() : _real((T)0), _imag((T)0) {
}

template <typename T>
Complex<T>::Complex(T real) : _real(real), _imag((T)0) {
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
bool Complex<T>::fromString(const std::string &s) {
    int i_pos = s.find('i');
    if (i_pos == -1) {
        std::cerr << "Can't read complex " << s << std::endl;
        return false;
    }
    T real, imag;
    std::stringstream ss;
    ss.str(s.substr(0, i_pos-1)); // by -i or +i
    ss >> real;
    if (ss.fail()) {
        std::cerr << "Can't read complex real part" << s.substr(0, i_pos-1) << std::endl;
        return false;
    }
    ss.str(s.substr(i_pos+1)); // after i
    ss >> imag;
    if (ss.fail()) {
        std::cerr << "Can't read complex imaginary part" << s.substr(i_pos+1) << std::endl;
        return false;
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
    if (c._imag >= (T)0) {
        out << "+" << c._imag;
    } else {
        out << "-" << (- c._imag);
    }
    out << "i";
    return out;
}

template <typename T>
std::istream& operator >> (std::istream &in, const Complex<T> &c) {
    std::string s;
    in >> s;
    c.fromString(s);
    return in;
}

template <typename T>
Complex<T> Complex<T>::operator = (const Complex<T> &c) {
    return Complex<T>(this->_real = c._real, this->_imag = c._imag);
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
                      c1._real = c1._imag + c2._imag);
}

template <typename T>
Complex<T> operator -= (Complex<T> &c1, const Complex<T> &c2) {
    return Complex<T>(c1._real = c1._real - c2._real,
                      c1._real = c1._imag - c2._imag);
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
    return Complex<T>(c1._real = c1._real * c2._real - c1._imag * c2._imag,
                      c1._imag = c1._imag * c2._real + c1._real * c2._imag);
}

template <typename T>
Complex<T> operator /= (Complex<T> &c1, const Complex<T> &c2) {
    return Complex<T>(c1._real = (c1._real * c2._real + c1._imag * c2._imag)/(c2._real*c2._real + c2._imag*c2._imag),
                      c2._imag = (c2._real * c1._imag - c1._real * c2._imag)/(c2._real*c2._real + c2._imag*c2._imag));
}

template <typename T>
const bool operator == (const Complex<T> &c1, const Complex<T> &c2) {
    return (c1._real == c2._real && c1._imag == c2._real);
}

template <typename T>
const bool operator != (const Complex<T> &c1, const Complex<T> &c2) {
    return !(c1 == c2);
}

template <typename T>
Complex<T>::operator bool() const {
    return !(_real == (T)0 && _imag == (T)0);
}

template class Complex<float>;
template class Complex<double>;
template class Complex<long double>;
