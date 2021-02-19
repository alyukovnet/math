/*!
 * @file Complex class declaration
 */
#ifndef COMPLEX_H
#define COMPLEX_H

#include <string>

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
     * Copy constructor
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
     * @return Output stream
     */
    friend std::ostream& operator << (std::ostream &out, const Complex<T> &c);

    /*!
     * Input from stream
     * @param[in] in Input stream
     * @param[out] c Complex number
     * @return Input stream
     */
    friend std::istream& operator >> (std::istream &in, const Complex<T> &c);

    /*!
     * Assignment operator
     * @param[in] c Complex number
     * @return Set complex number
     */
    Complex<T> operator = (const Complex<T> &c);

    /*!
     * Unary plus
     * @param[in] c Complex number
     * @return Unchanged complex number
     */
    friend Complex<T> operator + (const Complex<T> &c);

    /*!
     * Additive inverse
     * @param[in] c Complex number
     * @return Additive inverse complex number
     */
    friend Complex<T> operator - (const Complex<T> &c);

    /*!
     * Addition
     * @param[in] c1 Complex number
     * @param[in] c2 Complex number
     * @return Sum of the numbers
     */
    friend Complex<T> operator + (const Complex<T> &c1, const Complex<T> &c2);

    /*!
     * Subtraction
     * @param[in] c1 Complex number
     * @param[in] c2 Complex number
     * @return Difference of the numbers
     */
    friend Complex<T> operator - (const Complex<T> &c1, const Complex<T> &c2);

    /*!
     * Addition
     * @param[in,out] c1 Complex number
     * @param[in] c2 Complex number
     * @return Sum of the numbers
     */
    friend Complex<T> operator += (Complex<T> &c1, const Complex<T> &c2);

    /*!
     * Subtraction
     * @param[in,out] c1 Complex number
     * @param[in] c2 Complex number
     * @return Sum of the numbers
     */
    friend Complex<T> operator -= (Complex<T> &c1, const Complex<T> &c2);

    /*!
     * Multiplication
     * @param[in] c1 Complex number
     * @param[in] c2 Complex number
     * @return Multiplication of the numbers
     */
    friend Complex<T> operator * (const Complex<T> &c1, const Complex<T> &c2);

    /*!
     * Division
     * @param[in] c1 Complex number
     * @param[in] c2 Complex number
     * @return Division of the numbers
     */
    friend Complex<T> operator / (const Complex<T> &c1, const Complex<T> &c2);

    /*!
     * Multiplication
     * @param[in,out] c1 Complex number
     * @param[in] c2 Complex number
     * @return Multiplication of the numbers
     */
    friend Complex<T> operator *= (Complex<T> &c1, const Complex<T> &c2);

    /*!
     * Division
     * @param[in,out] c1 Complex number
     * @param[in] c2 Complex number
     * @return Division of the numbers
     */
    friend Complex<T> operator /= (Complex<T> &c1, const Complex<T> &c2);

    /*!
     * Compare for equality
     * @param[in] c1 Complex number
     * @param[in] c2 Complex number
     * @return Equality of the numbers
     */
    friend const bool operator == (const Complex<T> &c1, const Complex<T> &c2);

    /*!
     * Compare for inequality
     * @param[in] c1 Complex number
     * @param[in] c2 Complex number
     * @return Inequality of the numbers
     */
    friend const bool operator != (const Complex<T> &c1, const Complex<T> &c2);

    /*!
     * Check if number is zero
     * @return True if not zero
     */
    operator bool() const;
};

#endif //COMPLEX_H
