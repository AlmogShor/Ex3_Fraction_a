//
// Created by shora on 15/04/2023.
//

#include "sources/Fraction.hpp"
#include <iostream>
#include "doctest.h"

#include <stdexcept>

using namespace std;
using namespace ariel;

TEST_CASE("init - Ctors") {

    SUBCASE("Test 1: Throw exception when denominator is 0") {

        CHECK_THROWS(Fraction(1, 0));

        CHECK_THROWS(Fraction(0, 0));

    }
    SUBCASE("Test 2: No exception when numerator is not 0") {

        CHECK_NOTHROW(Fraction(1, 1));

        CHECK_NOTHROW(Fraction(0, -1));

        SUBCASE("Test 3: reducing the fraction to zero when needed while creating it") {

//            CHECK_EQ((double) Fraction(0, 1), 0);
            CHECK_EQ(Fraction(0, 1) == 0, true);
            CHECK_EQ(Fraction(0, 1) == 1, false);
            CHECK_EQ(Fraction(0, -1) == 0, true);
            CHECK_EQ(Fraction(0, 1), Fraction(0, -1));

//            CHECK_EQ((double) Fraction(0, -1), 0);

        }

    }
    SUBCASE("Test 4: reducing the fraction while creating it") {

        CHECK_EQ(Fraction(2, 4), Fraction(1, 2));

        CHECK_EQ(Fraction(2, -4), Fraction(-1, 2));
        CHECK_EQ(Fraction(-2, 4), Fraction(-1, 2));
        CHECK_EQ(Fraction(-2, -4), Fraction(1, 2));
    }

}

TEST_CASE("reducing to 3 digit after the dot") {

    SUBCASE("Test 5: simple reducing to complete numbers") {

    }
    SUBCASE("TTest 6: reducing after math operations that makes an overflow to 4 digits after the dot") {

    }

    SUBCASE("Test 7: chake with known Rational numbers Equalization") {

    }
}

TEST_CASE("checking constructor from input") {
    SUBCASE("Test 8: check with known Rational numbers Equalization") {

    }

    SUBCASE("Test 9: creating from basic input") {
        SUBCASE("sub test 9a: full numbers and reducing") {

        }
        SUBCASE("sub test 9b: fraction numbers and  reducing") {

        }
    }
    SUBCASE("Test 10: throw exception when denominator is 0") {

    }
    SUBCASE("Test 11: throw exception when wrong char between numerator and denominator") {

    }

}
