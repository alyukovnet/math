#include "matrix.h"

#include <iostream>
#include <istream>
#include <ostream>
#include <fstream>
#include <sstream>

Matrix::Matrix() {
    _m = {{0}};
    _h = 1;
    _w = 1;
}

Matrix::Matrix(int h, int w) {
    _m = std::vector<std::vector<int>>(h, std::vector<int>(w, 0));
    _h = h;
    _w = w;
}

bool Matrix::checkAndSet(std::vector<std::vector<int>> m) {
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

bool Matrix::fromStream(std::istream &in) {
    std::vector<std::vector<int>> m;
    if (in) {
        std::string line;
        int j = 0;
        while (std::getline(in, line)) {
            // Parse the line using a string stream
            std::istringstream row(line);
            m.push_back({});
            int got;
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

Matrix::Matrix(std::vector<std::vector<int>> m) {
    checkAndSet(m);
}

Matrix::Matrix(const Matrix& from) {
    _m = from._m;
    _w = from._w;
    _h = from._h;
}

bool Matrix::input() {
    return fromStream(std::cin);
}

bool Matrix::interactiveInput() {
    int h, w;
    std::cout << "Введите высоту матрицы: ";
    std::cin >> h;
    std::cout << "Введите ширину матрицы: ";
    std::cin >> w;

    std::vector<std::vector<int>> m(h, std::vector<int>(w, 0));
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

bool Matrix::toStream(std::ostream& out) {
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

bool Matrix::show() {
    return toStream(std::cout);
}

bool Matrix::set(int x, int y, int n) {
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

int Matrix::get(int x, int y) {
    if (x < 0 || x >= _w) {
        std::cerr << "Индекс X не существует" << std::endl;
        return false;
    }
    if (y < 0 || y >= _h) {
        std::cerr << "Индекс Y не существует" << std::endl;
        return false;
    }
    return _m[y][x];
}

bool Matrix::load(std::string filename) {
    std::ifstream fin(filename);
    return fromStream(fin);
}

bool Matrix::write(std::string filename) {
    std::ofstream f(filename);
    return toStream(f);
}

Matrix& Matrix::operator=(const Matrix& from) {
    _w = from._w;
    _h = from._h;
    _m = from._m;
    return *this;
}

Matrix operator+(const Matrix& m1, const Matrix& m2) {
    if (m1._h != m2._h || m1._w != m2._w) {
        std::cerr << "Невозможно сложить матрицы" << std::endl;
        Matrix result;
        return result;
    }
    Matrix result(m1._h, m2._w);
    for (int i = 0; i < m1._h; i++) {
        for (int j = 0; j < m1._w; j++) {
            result._m[i][j] = m1._m[i][j] + m2._m[i][j];
        }
    }
    return result;
}

Matrix Matrix::operator+=(const Matrix& m) {
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

Matrix operator*(const Matrix& m1, const Matrix& m2) {
    if (m1._w != m2._h) {
        std::cerr << "Невозможно умножить матрицы" << std::endl;
        Matrix result;
        return result;
    }
    Matrix result(m1._h, m2._w);
    for (int i = 0; i < m1._h; i++) {
        for (int j = 0; j < m2._w; j++) {
            for (int k = 0; k < m1._w; k++) {
                result._m[i][j] += m1._m[i][k] * m2._m[k][j];
            }
        }
    }
    return result;
}

Matrix Matrix::operator*=(const Matrix& m) {
    if (_w != m._h) {
        std::cerr << "Невозможно умножить матрицы" << std::endl;
        return *this;
    }
    std::vector<std::vector<int>> _mnew = std::vector<std::vector<int>>(_h, std::vector<int>(_w, 0));
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
