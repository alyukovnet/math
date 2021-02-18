#include "matrix.h"
#include <vector>

int main(int argc, char* argv[]) {
//    Matrix m1({{1, 2, 3},{4, 5, 6}}); // Works!
    //Matrix m1, m2;
    Matrix m1({{1, 2, 3}});
    Matrix m2({{1,},{2,},{3}});
    m1*=m2;
    m1.show();
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
