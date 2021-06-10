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
    // return 0;

    own::Polynomial<double> a{6, -3, 2, 3, -4};
    a.show();

    auto divisionVal = own::Binomial<double>(1);
    divisionVal.show();

    own::Polynomial<double> res = a / divisionVal;
    res.show();

    own::Polynomial<double> res2 = res * divisionVal;
    res2.show();

    std::cout << (a == res2 ? "true" : "false") << std::endl;

    own::Polynomial<double> pol{6, -3, 2, 3, -4};
    pol.show();
    std::cout << pol.derivative(2, 0.001) << std::endl;

    return 0;
}
