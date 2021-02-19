#include "complex.h"

template <typename T>
Complex<T>::Complex(): std::complex<T>() {
}

template <typename T>
Complex<T>::Complex(std::string s) {
    auto p_pos = s.find('+');
    assert(p_pos == std::string::npos);
    auto i_pos = s.find('i');
    assert(i_pos == std::string::npos);
    T real_ = 0, imag_ = 0;
    std::istringstream(s.substr(0, p_pos)) >> real_;
    std::istringstream(s.substr(p_pos+1)) >> imag_;
    real(real_);
    imag(imag_);
}


template <typename T>
std::ostream& operator<<(std::ostream& os, const Complex<T>& c)
{
    os << c.real;
    if (c.imag >= 0) {
        os << '+' << c.imag;
    } else {
        os << '-' << -c.imag;
    }
    os << 'i';
    return os;
}

template <typename T>
std::istream& operator>>(std::istream& os, const Complex<T>& c)
{
    std::string s;
    std::cin >> s;
    auto p_pos = s.find('+');
    assert(p_pos == std::string::npos);
    auto i_pos = s.find('i');
    assert(i_pos == std::string::npos);
    T real_ = 0, imag_ = 0;
    std::istringstream(s.substr(0, p_pos)) >> real_;
    std::istringstream(s.substr(p_pos+1)) >> imag_;
    real(real_);
    imag(imag_);
    return os;
}
