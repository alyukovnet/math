#include "matrix.h"
#include <vector>
#include <complex>
#include "complex.h"


int main(int argc, char* argv[]) {
//    Matrix m1({{1, 2, 3},{4, 5, 6}}); // Works!
//    Matrix<int> m1;
    //Matrix<std::complex<double>> m1({{std::complex<double>(1,2), std::complex<double>(3,2), std::complex<double>(3,4)}});
    //Matrix<std::complex<double>> m2({{std::complex<double>(1,5)},{std::complex<double>(2,1)},{std::complex<double>(3,9)}});

    Complex<double> c("1+1i");
    std::cout << c << std::endl;
    Complex<double> c1;
    std::cin >> c1;
    std::cout << c1 << std::endl;
//    m1*=m2;m1.show();
//    Matrix m2;
//    m2.load("mat4.txt");
//    m2.show();
//    Matrix m3({{1, 2, 3},{4, 5, 6}});
//    m3 = m2;
//    m3.show();
//    m2.interactiveInput(); // Works!
//    m2.show();
//    Matrix m3;
//    m3.load("mat1.txt"); // Works!
//    m3.show();
//    Matrix m4;
//    m4.input(); // Works!
//    m4.show();

    return 0;
}
