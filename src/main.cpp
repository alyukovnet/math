#include <iostream>
#include "complex.h"

int main(int argc, char* argv[]) {
    Complex<float> a(1.0);
    a = Complex<float>(2.0, 4.1);
    //std::cout << a;
//    std::cout << a.real() << " " << a.imag() << "\n";
    std::cin >> a;
    std::cout << a.real() << " " << a.imag() << "\n";
    return 0;
}
