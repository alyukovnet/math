#include <iostream>
#include <own.h>

int main(int argc, char* argv[]) {
    own::Matrix<own::Complex<double>> m1, m2;
    m1.load("../mat2.txt");
    m2.load("../mat3.txt");
    std::cout << m1 << std::endl;
    std::cout << m2 << std::endl;
    std::cout << (m1*m2) << std::endl;
    std::cout << m1*own::Complex<double>(2, 1) << std::endl;
    return 0;
}
