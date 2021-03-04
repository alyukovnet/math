#include "own/matrix.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

namespace own {

template <typename T>
Matrix<T>::Matrix() {
    _h = 1;
    _w = 1;
    **_a = new T *[1];
    _a[0] = new T[1];
    _a[0][0] = (T) 0;
}

template <typename T>
Matrix<T>::Matrix(int h, int w): _h(h), _w(w) {
    **_a = new T *[_h];
    for (int i = 0; i < _h; i++) {
        _a[i] = new T[_w];
        for (int j = 0; j < _w; j++)
            _a[i][j] = (T) 0;
    }
}

//template <typename T>
//Matrix<T>::Matrix(int h, int w, T **a): _h(h), _w(w) {
//    **_a = new T *[_h];
//    for (int i = 0; i < _h; i++) {
//        _a[i] = new T[_w];
//        for (int j = 0; j < _w; j++) {
//            try {
//                _a[i][j] = a[i][j];
//            } catch(const std::exception &error) {
//                _a[i][j] = (T) 0;
//            }
//        }
//    }
//}

template <typename T>
Matrix<T>::Matrix(const Matrix& from) {
    _w = from._w;
    _h = from._h;
    **_a = new T *[_h];
    for (int i = 0; i < _h; i++) {
        _a[i] = new T[_w];
        for (int j = 0; j < _w; j++)
            _a[i][j] = from._a[i][j];
    }
}

template <typename T>
Matrix<T>::~Matrix() {
    for (int i = 0; i < _h; i++)
        delete [] _a[i];
    delete [] _a;
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
    _a[y][x] = n;
    return true;
}

template <typename T>
T Matrix<T>::get(int x, int y) {
    if (x < 0 || x >= _w) {
        std::cerr << "Индекс X не существует" << std::endl;
        return (T) 0;
    }
    if (y < 0 || y >= _h) {
        std::cerr << "Индекс Y не существует" << std::endl;
        return (T) 0;
    }
    return _a[y][x];
}

template <typename T>
std::ostream& operator << (std::ostream &out, const Matrix<T> &c) {
    for (int i = 0; i < c._h; i++) {
        for (int j = 0; j < c._w; j++) {
            out << c._a[i][j] << " ";
        }
        out << std::endl;
    }
    return out;
}

template <typename T>
std::istream& operator >> (std::istream &in, Matrix<T> &c) {
    std::vector<std::vector<T>> m;
    int max_width = 0;
    if (in) {
        std::string line;
        int j = 0;
        while (std::getline(in, line)) {
            std::istringstream row(line);
            m.push_back({});
            T got;
            int width = 0;
            while (row >> got) {
                m[j].push_back(got);
                width++;
            }
            max_width = std::max(max_width, width);
            if (m[j].size() == 0) {
                m.pop_back();
                break;
            }
            j++;
        }

        c._h = m.size();
        c._w = max_width;
        **c._a = new T *[c._h];
        for (int i = 0; i < c._h; i++) {
            c._a[i] = new T[c._w];
            for (int j = 0; j < c._w; j++) {
                try {
                    c._a[i][j] = m[i][j];
                } catch(const std::exception &error) {
                    c._a[i][j] = (T) 0;
                }
            }
        }
    }
    return in;
}

//template <typename T>
//bool Matrix<T>::interactiveInput() {
//    int h, w;
//    std::cout << "Input height: ";
//    std::cin >> h;
//    std::cout << "Input width: ";
//    std::cin >> w;
//
//    T **a = new T *[_h];
//    std::cout << "Input values: " << std::endl;
//
//    for (int i = 0; i < h; i++) {
//        a[i] = new T[w];
//        for (int j = 0; j < w; j++) {
//            try {
//                std::cin >> a[i][j];
//            } catch (const std::exception &error) {
//                a[i][j] = (T) 0;
//            }
//        }
//    }
//    std::cout << "Input success" << std::endl;
//    _a = a;
//    _h = h;
//    _w = w;
//    return true;
//}

//template <typename T>
//T& Matrix<T>::operator()(int x, int y) {
//    assert(x < 0 || x >= _w);
//    assert(y < 0 || y >= _h);
//    return _a[y][x];
//}

template <typename T>
bool Matrix<T>::load(std::string filename) {
    std::ifstream in(filename);
    in >> *this;
    return true;
}

template <typename T>
bool Matrix<T>::save(std::string filename) {
    std::ofstream out(filename);
    out << *this;
    return true;
}

//template <typename T>
//Matrix<T>& Matrix<T>::operator=(const Matrix<T>& from) {
//    _w = from._w;
//    _h = from._h;
//    **_a = new T *[_h];
//    for (int i = 0; i < _h; i++) {
//        _a[i] = new T[_w];
//        for (int j = 0; j < _w; j++)
//            _a[i][j] = from._a[i][j];
//    }
//    return *this;
//}

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
            result._a[i][j] = m1._a[i][j] + m2._a[i][j];
        }
    }
    return result;
}

template <typename T>
Matrix<T> Matrix<T>::operator+=(const Matrix<T>& m) {
    if (_h != m._h || _w != m._w) {
        std::cerr << "Невозможно сложить матрицы" << std::endl;
        return *this;
    }
    for (int i = 0; i < m._h; i++) {
        for (int j = 0; j < m._w; j++) {
            _a[i][j] += m._a[i][j];
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
    Matrix result(m1._h, m2._w);
    for (int i = 0; i < m1._h; i++) {
        for (int j = 0; j < m2._w; j++) {
            for (int k = 0; k < m1._w; k++) {
                result._a[i][j] += m1._a[i][k] * m2._a[k][j];
            }
        }
    }
    return result;
}

template <typename T>
Matrix<T> Matrix<T>::operator*=(const Matrix<T>& m) {
    if (_w != m._h) {
        std::cerr << "Невозможно умножить матрицы" << std::endl;
        return *this;
    }
    std::vector<std::vector<T>> _anew(_h, std::vector<T>(_w, (T)0));
    for (int i = 0; i < _h; i++) {
        for (int j = 0; j < m._w; j++) {
            for (int k = 0; k < _w; k++) {
                _anew[i][j] += _a[i][k] * m._a[k][j];
            }
        }
    }
    _w = m._w;
    _a = _anew;
    return *this;
}

template <typename T>
Matrix<T> operator*(const Matrix<T>& m1, T t) {
    Matrix result(m1._h, m1._w);
    for (int i = 0; i < m1._h; i++) {
        for (int j = 0; j < m1._w; j++) {
            result._a[i][j] = m1._a[i][j] * t;
        }
    }
    return result;
}

template <typename T>
Matrix<T> Matrix<T>::operator*=(T t) {
    for (int i = 0; i < _h; i++) {
        for (int j = 0; j < _w; j++) {
            _a[i][j] *= t;
        }
    }
    return *this;
}

template <typename T>
Matrix<T> operator*(T t, const Matrix<T>& m2) {
    Matrix result(m2._h, m2._w);
    for (int i = 0; i < m2._h; i++) {
        for (int j = 0; j < m2._w; j++) {
            result._a[i][j] = t * m2._a[i][j];
        }
    }
    return result;
}

} //namespace own
