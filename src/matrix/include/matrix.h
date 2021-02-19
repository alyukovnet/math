/*!
\file
\brief Заголовочный файл класса Матрица

*/
#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <string>
#include <complex>

/*!
\brief Матрица

Описание

*/
template <typename T>
class Matrix {
private:
    std::vector<std::vector<T>> _m; //!< Матрица
    int _h; //!< Высота
    int _w; //!< Ширина

    /*!
    Проверка матрицы на валидность и установка
    \result Отсутствие ошибки
    */
    bool checkAndSet(std::vector<std::vector<T>>);

public:
    /*!
    Конструктор без параметров
    */
    Matrix();

    /*!
    Конструктор с размерами матрицы
    */
    Matrix(int, int);

    /*!
    Конструктор из векторов
    \param[in] m
    */
    Matrix(std::vector<std::vector<T>>);

    /*!
    Конструктор копирования
    \param[in] from Исходный объект
    */
    Matrix(const Matrix&);

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
    bool toStream(std::ostream&);

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
    Matrix& operator=(const Matrix&);

    /*!
    Суммирование матриц
    \result Сумма матриц
    */
    friend Matrix operator+(const Matrix&, const Matrix&);

    /*!
    Суммирование матриц
    */
    Matrix operator+=(const Matrix&);

    /*!
    Умножение матриц
    \result Произведение матриц
    */
    friend Matrix operator*(const Matrix&, const Matrix&);

    /*!
    Умножение матриц
    */
    Matrix operator*=(const Matrix&);

    /*!
    Умножение матрицы на T
    \result Произведение матриц
    */
    friend Matrix operator*(const Matrix&, T);

    /*!
    Умножение матрицы на T
    */
    Matrix operator*=(T);

    /*!
    Умножение T на матрицу
    \result Произведение матриц
    */
    friend Matrix operator*(T, const Matrix&);
};


#endif //MATRIX_H
