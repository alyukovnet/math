/*!
\file
\brief Заголовочный файл класса Матрица

*/
#ifndef OWN_MATRIX_H
#define OWN_MATRIX_H

#include <vector>
#include <string>
#include <iostream>

namespace own {

/*!
 * @brief Matrix
 * @tparam T Data type
 */
template <typename T>
class Matrix {
private:
    T **_a; //!< Matrix
    int _h; //!< Height
    int _w; //!< Width

public:
    /*!
     * Null matrix 1x1
     */
    Matrix();

    /*!
     * Matrix from height and width,
     * @param[in] h Height
     * @param[in] w Width
     */
    Matrix(int h, int w);

    /*!
     * Matrix from 2D array
     * @param[in] a 2D array
    */
    Matrix(int h, int w, T **a);

    /*!
     * Copy constructor
     * @param[in] from Original object
    */
    Matrix(const Matrix& from);

    /*!
     * Destructor
     */
    ~Matrix();

    /*!
     * Element value set
     * @param[in] x X
     * @param[in] y Y
     * @param[in] n Value
     * @result Отсутствие ошибки
     */
    bool set(int x, int y, T v);

    /*!
     * Получение значения поля
     * @param[in] x X
     * @param[in] y Y
     * @result Value
     */
    T get(int x, int y);

    /*!
     * Interactive input from std::cin (deprecated)
     * @return True if not errors
     */
    bool interactiveInput();

    /*!
     * Output to stream
     * @param[out] out Output stream
     * @param[in] m Matrix
     * @tparam U Number type
     * @return Output stream
     */
    template <typename U>
    friend std::ostream& operator << (std::ostream &out, const Matrix<U> &m);

    /*!
     * Input from stream
     * @param[in] in Input stream
     * @param[out] m Matrix
     * @tparam U Number type
     * @return Input stream
     */
    template <typename U>
    friend std::istream& operator >> (std::ostream &out, const Matrix<U> &c);

    /*!
     * Импорт из файла
     * @param[in] filename Имя файла
     * @result Отсутствие ошибки
    */
    bool load(std::string);

    /*!
     * Экспорт в файл
     * @param[out] filename Имя файла
     * @result Отсутствие ошибки
    */
    bool save(std::string);

    /*!
     * Assignment operator
     * @param[in] Matrix
     * @result
     */
    Matrix& operator=(const Matrix &m);

    /*!
     * Assignment operator
     * @param[in] 2D array
     * @result
     */
    Matrix& operator=(const T **a);

    /*!
     * Суммирование матриц
     * @result Сумма матриц
     */
    friend Matrix operator+(const Matrix &m1, const Matrix &m2);

    /*!
     * Суммирование матриц
     */
    Matrix operator+=(const Matrix &m);

    /*!
     * Умножение матриц
     * @result Произведение матриц
    */
    friend Matrix operator*(const Matrix &m1, const Matrix &m2);

    /*!
     * Умножение матриц
     */
    Matrix operator*=(const Matrix &m);

    /*!
     * Умножение матрицы на T
     * @result Произведение матриц
     */
    friend Matrix operator*(const Matrix &m, T v);

    /*!
     * Умножение матрицы на T
     */
    Matrix operator*=(T v);

    /*!
     * Умножение T на матрицу
     * @result Произведение матриц
     */
    friend Matrix operator*(T v, const Matrix &m);

};

} //namespace own

#endif //OWN_MATRIX_H
