//
// Created by shora on 15/04/2023.
//

#include "sources/Fraction.hpp"
#include <iostream>
#include "doctest.h"

#inclode <stdexcept>

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

            CHECK_EQ((double) Fraction(0, 1), 0);

            CHECK_EQ((double) Fraction(0, -1), 0);

        }

    }
    SUBCASE("Test 4: reducing the fraction while creating it") {

        CHECK_EQ(Fraction(2, 4), Fraction(1, 2));

        CHECK_EQ(Fraction(2, -4), Fraction(-1, 2));
        CHECK_EQ(Fraction(-2, 4), Fraction(-1, 2));
        CHECK_EQ(Fraction(-2, -4), Fraction(1, 2));
    }



}