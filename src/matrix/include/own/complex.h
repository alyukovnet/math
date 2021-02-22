/*!
 * @file Complex class declaration
 */
#ifndef OWN_COMPLEX_H
#define OWN_COMPLEX_H

#include <string>

namespace own {

/*!
 * @brief Complex number
 * @tparam T Number type
 */
template <typename T>
class Complex {
private:
    T _real; //!< Real part
    T _imag; //!< Imaginary part
public:
    /*!
     * Default complex number 0+0i
     */
    Complex();

    /*!
     * Complex number from real part (imaginary = 0)
     * @param[in] real Real part
     */
    Complex(T real);

    /*!
     * Complex number from real and imaginary parts
     * @param[in] real Real part
     * @param[in] imag Imaginary part
     */
    Complex(T real, T imag);

    /*!
     * Copy constructor (default)
     * @param c Original object
     */
    Complex(const Complex<T> &c);

    /*!
     * Complex number from string
     * Supported: n+mi, -n+mi, n-mi, -n-mi
     * @param[in] s String
     */
    Complex(const std::string &s);

    /*!
     * Destructor
     */
    ~Complex();

    /*!
     * Set complex number from string
     * Supported: n+mi, -n+mi, n-mi, -n-mi
     * @param s String
     * @return True if success
     */
    bool fromString(const std::string &s);

    /*!
     * Get real part
     * @return Real part
     */
    T real();

    /*!
     * Get imaginary part
     * @return Imaginary part
     */
    T imag();

    /*!
     * Set real part
     * @param[in] real Real part
     */
    void real(T real);

    /*!
     * Set imaginary part
     * @param[in] imag Imaginary part
     */
    void imag(T imag);

    /*!
     * Output to stream
     * @param[out] out Output stream
     * @param[in] c Complex number
     * @tparam U Number type
     * @return Output stream
     */
    template <typename U>
    friend std::ostream& operator << (std::ostream &out, const Complex<U> &c);

    /*!
     * Input from stream
     * @param[in] in Input stream
     * @param[out] c Complex number
     * @tparam U Number type
     * @return Input stream
     */
    template <typename U>
    friend std::istream& operator >> (std::istream &in, Complex<U> &c);

    /*!
     * Assignment operator (default)
     * @param[in] c Complex number
     * @return Set complex number
     */
    Complex<T>& operator = (const Complex<T> &c);

    /*!
     * Unary plus
     * @param[in] c Complex number
     * @tparam U Number type
     * @return Unchanged complex number
     */
    template <typename U>
    friend Complex<U> operator + (const Complex<U> &c);

    /*!
     * Additive inverse
     * @param[in] c Complex number
     * @tparam U Number type
     * @return Additive inverse complex number
     */
    template <typename U>
    friend Complex<U> operator - (const Complex<U> &c);

    /*!
     * Addition
     * @param[in] c1 Complex number
     * @param[in] c2 Complex number
     * @tparam U Number type
     * @return Sum of the numbers
     */
    template <typename U>
    friend Complex<U> operator + (const Complex<U> &c1, const Complex<U> &c2);

    /*!
     * Subtraction
     * @param[in] c1 Complex number
     * @param[in] c2 Complex number
     * @tparam U Number type
     * @return Difference of the numbers
     */
    template <typename U>
    friend Complex<U> operator - (const Complex<U> &c1, const Complex<U> &c2);

    /*!
     * Addition
     * @param[in,out] c1 Complex number
     * @param[in] c2 Complex number
     * @tparam U Number type
     * @return Sum of the numbers
     */
    template <typename U>
    friend Complex<U> operator += (Complex<U> &c1, const Complex<U> &c2);

    /*!
     * Subtraction
     * @param[in,out] c1 Complex number
     * @param[in] c2 Complex number
     * @tparam U Number type
     * @return Sum of the numbers
     */
    template <typename U>
    friend Complex<U> operator -= (Complex<U> &c1, const Complex<U> &c2);

    /*!
     * Multiplication
     * @param[in] c1 Complex number
     * @param[in] c2 Complex number
     * @tparam U Number type
     * @return Multiplication of the numbers
     */
    template <typename U>
    friend Complex<U> operator * (const Complex<U> &c1, const Complex<U> &c2);

    /*!
     * Division
     * @param[in] c1 Complex number
     * @param[in] c2 Complex number
     * @tparam U Number type
     * @return Division of the numbers
     */
    template <typename U>
    friend Complex<U> operator / (const Complex<U> &c1, const Complex<U> &c2);

    /*!
     * Multiplication
     * @param[in,out] c1 Complex number
     * @param[in] c2 Complex number
     * @tparam U Number type
     * @return Multiplication of the numbers
     */
    template <typename U>
    friend Complex<U> operator *= (Complex<U> &c1, const Complex<U> &c2);

    /*!
     * Division
     * @param[in,out] c1 Complex number
     * @param[in] c2 Complex number
     * @tparam U Number type
     * @return Division of the numbers
     */
    template <typename U>
    friend Complex<U> operator /= (Complex<U> &c1, const Complex<U> &c2);

    /*!
     * Compare for equality
     * @param[in] c1 Complex number
     * @param[in] c2 Complex number
     * @tparam U Number type
     * @return Equality of the numbers
     */
    template <typename U>
    friend bool operator == (const Complex<U> &c1, const Complex<U> &c2);

    /*!
     * Compare for inequality
     * @param[in] c1 Complex number
     * @param[in] c2 Complex number
     * @tparam U Number type
     * @return Inequality of the numbers
     */
    template <typename U>
    friend bool operator != (const Complex<U> &c1, const Complex<U> &c2);

    /*!
     * Check if number is zero
     * @return True if not zero
     */
    explicit operator bool() const noexcept;
};

} //namespace own

// Complex class implementation
#include "../../src/complex.hh"

#endif //OWN_COMPLEX_H
