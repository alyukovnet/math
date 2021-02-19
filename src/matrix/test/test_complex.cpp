#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"

#include <sstream>
#include <string>
#include "complex.h"

TEST_CASE("Complex set and get methods", "[Complex]") {
    Complex<float> a;
    REQUIRE((bool) a == false);

    a = Complex<float>(1.0);
    REQUIRE(a.real() == 1.0);
    REQUIRE(a.imag() == 0.0);
    REQUIRE((bool) a == true);

    a = Complex<float>(2.0, 3.0);
    REQUIRE(a.real() == 2.0);
    REQUIRE(a.imag() == 3.0);
    REQUIRE((bool) a == true);

    a.real(11.1);
    REQUIRE(a.real() == 11.1);
    a.imag(12.3);
    REQUIRE(a.real() == 12.3);

    Complex<float> b(a);
    REQUIRE(a.real() == 11.1);
    REQUIRE(a.real() == 12.3);
}

TEST_CASE("Complex from string and iostream methods", "[Complex]") {
    Complex<float> a("3.3+4.4i");
    REQUIRE(a.real() == 3.3);
    REQUIRE(a.imag() == 4.4);

    a.fromString("-1.2-3.4i");
    REQUIRE(a.real() == -1.2);
    REQUIRE(a.imag() == -3.4);

    std::stringstream ss;
    ss.str("4.3-2.1i");
    ss >> a;
    REQUIRE(a.real() == 4.3);
    REQUIRE(a.imag() == -2.1);

    a.fromString("-1.2-3.4i");

    ss.str("");
    ss << a;
    std::string s;
    ss >> s;
    REQUIRE(s == "-1.2-3.4i");
}

TEST_CASE("Complex operators", "[Complex]") {
    Complex<float> a(1.2, -3.4);
    REQUIRE(+a == a);
    REQUIRE(-a == Complex<float>(-1.2, 3.4));

    Complex<float> b(2.0, 3.0);
    REQUIRE(a != b);
    REQUIRE(a + b == Complex<float>(3.2, -0.4));
    REQUIRE(a - b == Complex<float>(-0.8, -6.4));
    REQUIRE(a * b == Complex<float>(12.6, -3.2));
    REQUIRE(a / b == Complex<float>(-0.6, -0.8));

    SECTION("") {
        REQUIRE((a += b) == Complex<float>(3.2, -0.4));
        REQUIRE(a == Complex<float>(3.2, -0.4));
    }
    SECTION("") {
        REQUIRE((a -= b) == Complex<float>(-0.8, -6.4));
        REQUIRE(a == Complex<float>(-0.8, -6.4));
    }
    SECTION("") {
        REQUIRE((a += b) == Complex<float>(12.6, -3.2));
        REQUIRE(a == Complex<float>(12.6, -3.2));
    }
    SECTION("") {
        REQUIRE((a += b) == Complex<float>(-0.6, -0.8));
        REQUIRE(a == Complex<float>(-0.6, -0.8));
    }
}
