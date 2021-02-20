#include <iostream>
#include "matrix/include/own/complex.h"

int main(int argc, char* argv[]) {
    own::Complex<float> a(1.0);
    a = own::Complex<float>(2.0, 4.1);
    a.fromString("-2.1-4.3i");
    std::cout << a;
//    std::cout << a.real() << " " << a.imag() << "\n";
//    std::cin >> a;
//    std::cout << a.real() << " " << a.imag() << "\n";
    return 0;
}
