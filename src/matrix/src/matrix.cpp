#ifndef OWN_MATRIX_CPP
#define OWN_MATRIX_CPP

#include "own/matrix.h"
#include "own/complex.h"

#include <iostream>
#include <fstream>
#include <sstream>

namespace own {

template <typename T>
Matrix<T>::Matrix() {
    _m = {{(T)0}};
    _h = 1;
    _w = 1;
}

template <typename T>
Matrix<T>::Matrix(int h, int w) {
    _m = std::vector<std::vector<T>>(h, std::vector<T>(w, (T)0));
    _h = h;
    _w = w;
}

template <typename T>
bool Matrix<T>::checkAndSet(std::vector<std::vector<T>> m) {
    int h = m.size();
    if (h == 0) {
        std::cerr << "Ошибка. Высота матрицы 0" << std::endl;
        return false;
    }
    int w = m[0].size();
    for (int i = 1; i < h; i++) {
        if (m[i].size() != w) {
            std::cerr << "Ошибка. Ширина матрицы не совпадает" << std::endl;
            return false;
        }
    }
    if (w == 0) {
        std::cerr << "Ошибка. Ширина матрицы 0" << std::endl;
        return false;
    }
    _m = m;
    _h = m.size();
    _w = m[0].size();
    return true;
}

template <typename T>
bool Matrix<T>::fromStream(std::istream &in) {
    std::vector<std::vector<T>> m;
    if (in) {
        std::string line;
        int j = 0;
        while (std::getline(in, line)) {
            // Parse the line using a string stream
            std::istringstream row(line);
            m.push_back({});
            T got;
            while (row >> got) {
                m[j].push_back(got);
            }
            if (m[j].size() == 0) {
                m.pop_back();
                break;
            }
            j++;
        }
    }
    return checkAndSet(m);
}

template <typename T>
Matrix<T>::Matrix(std::vector<std::vector<T>> m) {
    checkAndSet(m);
}

template <typename T>
Matrix<T>::Matrix(const Matrix& from) {
    _m = from._m;
    _w = from._w;
    _h = from._h;
}

template <typename T>
bool Matrix<T>::input() {
    return fromStream(std::cin);
}

template <typename T>
bool Matrix<T>::interactiveInput() {
    int h, w;
    std::cout << "Введите высоту матрицы: ";
    std::cin >> h;
    std::cout << "Введите ширину матрицы: ";
    std::cin >> w;

    std::vector<std::vector<T>> m(h, std::vector<T>(w, (T)0));
    std::cout << "Введите значения матрицы: " << std::endl;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            std::cin >> m[i][j];
        }
    }
    std::cout << "Ввод окончен" << std::endl;
    _m = m;
    _h = m.size();
    _w = m[0].size();
    return true;
}

template <typename T>
bool Matrix<T>::toStream(std::ostream& out) const {
    if (_w == 0) {
        std::cerr << "Пустая матрица" << std::endl;
        return false;
    }
    for (int i = 0; i < _h; i++) {
        for (int j = 0; j < _w; j++) {
            out << _m[i][j] << " ";
        }
        out << std::endl;
    }
    return true;
}

template <typename T>
bool Matrix<T>::show() {
    return toStream(std::cout);
}

template <typename T>
bool Matrix<T>::set(int x, int y, T n) {
    if (x < 0 || x >= _w) {
        std::cerr << "Индекс X не существует" << std::endl;
        return false;
    }
    if (y < 0 || y >= _h) {
        std::cerr << "Индекс Y не существует" << std::endl;
        return false;
    }
    _m[y][x] = n;
    return true;
}

template <typename T>
T Matrix<T>::get(int x, int y) {
    if (x < 0 || x >= _w) {
        std::cerr << "Индекс X не существует" << std::endl;
        return (T)0;
    }
    if (y < 0 || y >= _h) {
        std::cerr << "Индекс Y не существует" << std::endl;
        return (T)0;
    }
    return _m[y][x];
}

template <typename T>
T& Matrix<T>::operator()(int x, int y) {
    assert(x < 0 || x >= _w);
    assert(y < 0 || y >= _h);
    return _m[y][x];
}

template <typename T>
const T& Matrix<T>::operator()(int x, int y) const {
    assert(x < 0 || x >= _w);
    assert(y < 0 || y >= _h);
    return _m[y][x];
}

template <typename T>
bool Matrix<T>::load(std::string filename) {
    std::ifstream fin(filename);
    return fromStream(fin);
}

template <typename T>
bool Matrix<T>::write(std::string filename) {
    std::ofstream f(filename);
    return toStream(f);
}

template <typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& from) {
    _w = from._w;
    _h = from._h;
    _m = from._m;
    return *this;
}

template <typename T>
Matrix<T> operator+(const Matrix<T>& m1, const Matrix<T>& m2) {
    if (m1._h != m2._h || m1._w != m2._w) {
        std::cerr << "Невозможно сложить матрицы" << std::endl;
        Matrix<T> result;
        return result;
    }
    Matrix<T> result(m1._h, m2._w);
    for (int i = 0; i < m1._h; i++) {
        for (int j = 0; j < m1._w; j++) {
            result._m[i][j] = m1._m[i][j] + m2._m[i][j];
        }
    }
    return result;
}

template <typename T>
Matrix<T>& Matrix<T>::operator+=(const Matrix<T>& m) {
    if (_h != m._h || _w != m._w) {
        std::cerr << "Невозможно сложить матрицы" << std::endl;
        return *this;
    }
    for (int i = 0; i < m._h; i++) {
        for (int j = 0; j < m._w; j++) {
            _m[i][j] += m._m[i][j];
        }
    }
    return *this;
}

template <typename T>
Matrix<T> operator-(const Matrix<T>& m1, const Matrix<T>& m2) {
    if (m1._h != m2._h || m1._w != m2._w) {
        std::cerr << "Невозможно сложить матрицы" << std::endl;
        Matrix<T> result;
        return result;
    }
    Matrix<T> result(m1._h, m2._w);
    for (int i = 0; i < m1._h; i++) {
        for (int j = 0; j < m1._w; j++) {
            result._m[i][j] = m1._m[i][j] - m2._m[i][j];
        }
    }
    return result;
}

template <typename T>
Matrix<T>& Matrix<T>::operator-=(const Matrix<T>& m) {
    if (_h != m._h || _w != m._w) {
        std::cerr << "Невозможно сложить матрицы" << std::endl;
        return *this;
    }
    for (int i = 0; i < m._h; i++) {
        for (int j = 0; j < m._w; j++) {
            _m[i][j] -= m._m[i][j];
        }
    }
    return *this;
}

template <typename T>
Matrix<T> operator*(const Matrix<T>& m1, const Matrix<T>& m2) {
    if (m1._w != m2._h) {
        std::cerr << "Невозможно умножить матрицы" << std::endl;
        Matrix<T> result;
        return result;
    }
    Matrix<T> result(m1._h, m2._w);
    for (int i = 0; i < m1._h; i++) {
        for (int j = 0; j < m2._w; j++) {
            for (int k = 0; k < m1._w; k++) {
                result._m[i][j] += m1._m[i][k] * m2._m[k][j];
            }
        }
    }
    return result;
}

template <typename T>
Matrix<T>& Matrix<T>::operator*=(const Matrix<T>& m) {
    if (_w != m._h) {
        std::cerr << "Невозможно умножить матрицы" << std::endl;
        return *this;
    }
    std::vector<std::vector<T>> _mnew(_h, std::vector<T>(_w, (T)0));
    for (int i = 0; i < _h; i++) {
        for (int j = 0; j < m._w; j++) {
            for (int k = 0; k < _w; k++) {
                _mnew[i][j] += _m[i][k] * m._m[k][j];
            }
        }
    }
    _w = m._w;
    _m = _mnew;
    return *this;
}

template <typename T>
Matrix<T> operator*(const Matrix<T>& m1, T t) {
    Matrix<T> result(m1._h, m1._w);
    for (int i = 0; i < m1._h; i++) {
        for (int j = 0; j < m1._w; j++) {
            result._m[i][j] = m1._m[i][j] * t;
        }
    }
    return result;
}

template <typename T>
Matrix<T>& Matrix<T>::operator*=(T t) {
    for (int i = 0; i < _h; i++) {
        for (int j = 0; j < _w; j++) {
            _m[i][j] *= t;
        }
    }
    return *this;
}

template <typename T>
Matrix<T> operator*(T t, const Matrix<T>& m2) {
    Matrix<T> result(m2._h, m2._w);
    for (int i = 0; i < m2._h; i++) {
        for (int j = 0; j < m2._w; j++) {
            result._m[i][j] = t * m2._m[i][j];
        }
    }
    return result;
}

template <typename T>
std::ostream& operator << (std::ostream &out, const Matrix<T> &c) {
    c.toStream(out);
    return out;
}

template <typename T>
std::istream& operator >> (std::istream &in, Matrix<T> &c) {
    c.fromStream(in);
    return in;
}


template class Matrix<int>;
template class Matrix<float>;
template class Matrix<double>;
template class Matrix<long>;
template class Matrix<long long>;

template class Matrix<std::complex<double>>;

template class Matrix<Complex<double>>;

} //namespace own

#endif //OWN_MATRIX_CPP
