/*!
\file
\brief Заголовочный файл класса Матрица

*/
#ifndef OWN_MATRIX_H
#define OWN_MATRIX_H

#include <vector>
#include <string>
#include <complex>

namespace own {

/*!
 * @brief Matrix
 * @tparam T Data type
 */
template <typename T>
class Matrix {
private:
    std::vector<std::vector<T>> _m; //!< Матрица
    int _h; //!< Height
    int _w; //!< Width

    /*!
    Проверка матрицы на валидность и установка
    \result Отсутствие ошибки
    */
    bool checkAndSet(std::vector<std::vector<T>>);

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
    Конструктор из векторов
    \param[in] m
    */
    Matrix(std::vector<std::vector<T>>);

    /*!
     * Copy constructor
     * @param[in] from Original object
    */
    Matrix(const Matrix& from);

    /*!
    Импорт матрицы из Stream
    \result Отсутствие ошибки
    */
    bool fromStream(std::istream&);

    /*!
    Импорт из консоли
    \result Отсутствие ошибки
    */
    bool input();

    /*!
    Интерактивный импорт из консоли
    \result Отсутствие ошибки
    */
    bool interactiveInput();

    /*!
    Экспорт матрицы в Stream
    \result Отсутствие ошибки
    */
    bool toStream(std::ostream&) const;

    /*!
    Вывод в консоль
    \result Отсутствие ошибки
    */
    bool show();

    /*!
    Установка значения поля
    \param[in] x
    \param[in] y
    \param[in] n
    \result Отсутствие ошибки
    */
    bool set(int, int, T);

    /*!
    Получение значения поля
    \param[in] x
    \param[in] y
    \result Значение поля
    */
    T get(int, int);

    /*!
    Получение значения поля
    \param[in] x
    \param[in] y
    \result Ссылка на поле
    */
    T& operator()(int, int);

    /*!
    Получение значения поля
    \param[in] x
    \param[in] y
    \result Ссылка на поле
    */
    const T& operator()(int, int) const;

    /*!
    Импорт из файла
    \param[in] filename Имя файла
    \result Отсутствие ошибки
    */
    bool load(std::string);

    /*!
    Экспорт в файл
    \param[out] filename Имя файла
    \result Отсутствие ошибки
    */
    bool write(std::string);

    /*!
    Оператор присваивания
    */
    Matrix<T>& operator=(const Matrix<T>&);

    /*!
    Суммирование матриц
    \result Сумма матриц
    */
    template <typename U>
    friend Matrix<U> operator+(const Matrix<U>&, const Matrix<U>&);

    /*!
    Суммирование матриц
    */
    Matrix<T>& operator+=(const Matrix<T>&);

    /*!
    Вычитание матриц
    \result Разность матриц
    */
    template <typename U>
    friend Matrix<U> operator-(const Matrix<U>&, const Matrix<U>&);

    /*!
    Вычитание матриц
    */
    Matrix<T>& operator-=(const Matrix<T>&);

    /*!
    Умножение матриц
    \result Произведение матриц
    */
    template <typename U>
    friend Matrix<U> operator*(const Matrix<U>&, const Matrix<U>&);

    /*!
    Умножение матриц
    */
    Matrix& operator*=(const Matrix<T>&);

    /*!
    Умножение матрицы на T
    \result Произведение матриц
    */
    template <typename U>
    friend Matrix<U> operator*(const Matrix<U>&, U);

    /*!
    Умножение матрицы на T
    */
    Matrix<T>& operator*=(T);

    /*!
    Умножение T на матрицу
    \result Произведение матриц
    */
    template <typename U>
    friend Matrix<U>& operator*(T, const Matrix<U>&);

    /*!
     * Output to stream
     * @param[out] out Output stream
     * @param[in] c Complex number
     * @tparam U Number type
     * @return Output stream
     */
    template <typename U>
    friend std::ostream& operator << (std::ostream &out, const Matrix<U> &c);

    /*!
     * Input from stream
     * @param[in] in Input stream
     * @param[out] c Complex number
     * @tparam U Number type
     * @return Input stream
     */
    template <typename U>
    friend std::istream& operator >> (std::istream &in, Matrix<U> &c);

};

} //namespace own

// Matrix class implementation
#include "../../src/matrix.cpp"

#endif //OWN_MATRIX_H
