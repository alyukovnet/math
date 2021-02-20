#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"

#include <sstream>
#include <string>
#include "own/complex.h"

using Catch::Matchers::Equals;

TEST_CASE("Complex set and get methods", "[Complex]") {
    own::Complex<double> a;
    REQUIRE((bool) a == false);

    a = own::Complex<double>(1.0);
    REQUIRE(a.real() == 1.0);
    REQUIRE(a.imag() == 0.0);
    REQUIRE((bool) a == true);

    a = own::Complex<double>(2.0, 3.0);
    REQUIRE(a.real() == 2.0);
    REQUIRE(a.imag() == 3.0);
    REQUIRE((bool) a == true);

    a.real(11.1);
    REQUIRE(a.real() == 11.1);
    a.imag(12.3);
    REQUIRE(a.imag() == 12.3);

    own::Complex<double> b(a);
    REQUIRE(a.real() == 11.1);
    REQUIRE(a.imag() == 12.3);
}

TEST_CASE("Complex from string and iostream methods", "[Complex]") {
    own::Complex<double> a("3.3+4.4i");
    REQUIRE(a.real() == 3.3);
    REQUIRE(a.imag() == 4.4);

    a.fromString("-1.2-3.4i");
    REQUIRE(a.real() == -1.2);
    REQUIRE(a.imag() == -3.4);

//    std::stringstream ss("4.3-2.1i");
//    ss >> a;
//    REQUIRE(a.real() == 4.3);
//    REQUIRE(a.imag() == -2.1);

//    a.fromString("-1.2-3.4i");
//    ss.str("");
//    ss.clear();
//    ss << a;
//    std::string s;
//    ss >> s;
//    REQUIRE(s == "-1.2-3.4i");
}

TEST_CASE("Complex operators", "[Complex]") {
    own::Complex<double> a(1.2, -3.4);
//    REQUIRE((+a) == a);
    REQUIRE(-a == own::Complex<double>(-1.2, 3.4));

//    own::Complex<double> b(2.0, 3.0);
//    REQUIRE(a != b);
//    REQUIRE(a + b == own::Complex<double>(3.2, -0.4));
//    REQUIRE(a - b == own::Complex<double>(-0.8, -6.4));
//    REQUIRE(a * b == own::Complex<double>(12.6, -3.2));
//    REQUIRE(a / b == own::Complex<double>(-0.6, -0.8));
//
//    SECTION("") {
//        REQUIRE((a += b) == own::Complex<double>(3.2, -0.4));
//        REQUIRE(a == own::Complex<double>(3.2, -0.4));
//    }
//    SECTION("") {
//        REQUIRE((a -= b) == own::Complex<double>(-0.8, -6.4));
//        REQUIRE(a == own::Complex<double>(-0.8, -6.4));
//    }
//    SECTION("") {
//        REQUIRE((a += b) == own::Complex<double>(12.6, -3.2));
//        REQUIRE(a == own::Complex<double>(12.6, -3.2));
//    }
//    SECTION("") {
//        REQUIRE((a += b) == own::Complex<double>(-0.6, -0.8));
//        REQUIRE(a == own::Complex<double>(-0.6, -0.8));
//    }
}
