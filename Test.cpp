//
// Created by shora on 15/04/2023.
//

#include "sources/Fraction.hpp"
#include <iostream>
#include "doctest.h"
#include <string>
#include <sstream>


#include <stdexcept>

using namespace std;
using namespace ariel;

TEST_CASE("init - Ctors") {
    /**
     * Fraction();                             // Default constructor
      * Fraction(int numerator, int denominator); // Constructor with numerator and denominator
      * Fraction(double value);                 // Constructor with value as a float
     */

    SUBCASE("Test 1: Throw exception when denominator is 0") {

        CHECK_THROWS(Fraction(1, 0));

        CHECK_THROWS(Fraction(0, 0));

    }
    SUBCASE("Test 2: No exception when numerator is not 0") {

        CHECK_NOTHROW(Fraction(1, 1));

        CHECK_NOTHROW(Fraction(0, -1));

        CHECK_NOTHROW(Fraction(-1, 1));

        SUBCASE("Test 3: reducing the fraction to zero when needed while creating it") {

            CHECK_EQ(Fraction(0, 1) == 0, true);
            CHECK_EQ(Fraction(0, 1) == 1, false);
            CHECK_EQ(Fraction(0, -1) == 0, true);
            CHECK_EQ(Fraction(0, 1), Fraction(0, -1));


        }

    }
    SUBCASE("Test 4: reducing the fraction while creating it") {

        CHECK_EQ(Fraction(2, 4), Fraction(1, 2));
        CHECK_EQ(Fraction(4, 2), Fraction(2, 1));
        CHECK_EQ(Fraction(2, -4), Fraction(-1, 2));
        CHECK_EQ(Fraction(-2, 4), Fraction(-1, 2));
        CHECK_EQ(Fraction(-2, -4), Fraction(1, 2));
    }
    SUBCASE("subtest: double ctor") {
        CHECK_NOTHROW(Fraction(1.0));
        CHECK_EQ(Fraction(1.0), Fraction(1, 1));
        CHECK_EQ(Fraction(1.0), Fraction(1000, 1000));
    }

}

TEST_CASE("reducing to 3 digit after the dot") {
    /**
     * private:
     *  mutable int numerator;   // Numerator of the fraction
     *  mutable int denominator; // Denominator of the fraction

        // Helper functions to reduce the fraction to its simplest form
     *  void reduce() const;

     * int gcd(int a, int b) const;
     */

    SUBCASE("Test 5: simple reducing to complete numbers") {
        Fraction f_1(10, 2);

        CHECK_EQ(f_1, Fraction(5, 1));
        CHECK_EQ(f_1, Fraction(5.0));


    }
    SUBCASE("subcase: simple reducing") {
        Fraction f_1(3, 9);
        CHECK_EQ(f_1, Fraction(1, 3));

        Fraction f_2(3, 6);
        CHECK_EQ(f_2, Fraction(1, 2));

        Fraction f_3(-12, 8);
        CHECK_EQ(f_3, Fraction(-3, 2));

        Fraction f_4(12, -8);
        CHECK_EQ(f_4, Fraction(-3, 2));

    }
    SUBCASE("Test 6: reducing af_ter math operations that makes an overflow to 4 digits af_ter the dot") {

        Fraction f_1(1, 3);
        Fraction f_2(1, 7);

        Fraction f_3 = f_1 + f_2;
        CHECK_EQ(f_3, Fraction(10, 21));
        CHECK_EQ(f_3, Fraction(0.476));

        Fraction f_4 = f_1 - f_2;
        CHECK_EQ(f_4, Fraction(4, 21));

        Fraction f_5 = f_1 * f_2;
        CHECK_EQ(f_5, Fraction(1, 21));

        Fraction f_6 = f_1 / f_2;
        CHECK_EQ(f_6, Fraction(7, 3));

    }


    SUBCASE("Test 7: check with known Rational numbers Equalization") {
        Fraction pi_num(3141, 1000);

//check equal to 3.141
        CHECK_EQ(pi_num, Fraction(3.141));
//check not equal to 3.14
        CHECK_NE(pi_num, Fraction(314, 100));

        Fraction e_num(2718, 1000);
//check equal to 2.718
        CHECK_EQ(e_num, Fraction(2.718));
//check not equal to 2.71
        CHECK_NE(e_num, Fraction(271, 100));

        Fraction f_2(1.234);
        CHECK_EQ(f_2, Fraction(617, 500));

        Fraction f_3(0.666666);
        CHECK_EQ(f_3, Fraction(2, 3));


    }
}

TEST_CASE("checking constructor from input") {
    /**
     * friend std::istream& operator>>(std::istream &is, Fraction &f_raction);      // Input f_rom stream
     */

    SUBCASE("Test 8: check with known Rational numbers Equalization") {
        Fraction pi_num(3141, 1000);
        stringstream ss1("3.141");
        Fraction f_1;
        CHECK_NOTHROW(ss1 >> f_1);
        CHECK_EQ(f_1, pi_num);

        Fraction e_num(2718, 1000);
        stringstream ss2("2.718");
        Fraction f_2;
        CHECK_NOTHROW(ss2 >> f_2);
        CHECK_EQ(f_2, e_num);

    }

    SUBCASE("Test 9: creating f_rom basic input") {
        stringstream ss1("4/8");
        Fraction f_1;
        CHECK_NOTHROW(ss1 >> f_1);
        CHECK_EQ(f_1, Fraction(1, 2));

        stringstream ss2("-12/8");
        Fraction f_2;

        CHECK_NOTHROW(ss2 >> f_2);
        CHECK_EQ(f_2, Fraction(-3, 2));

        stringstream ss3("8/12");
        Fraction f_3;
        CHECK_NOTHROW(ss3 >> f_3);
        CHECK_EQ(f_3, Fraction(2, 3));

        stringstream ss4("-2/7");
        Fraction f_4;
        CHECK_NOTHROW(ss4 >> f_4);
        CHECK_EQ(f_4, Fraction(-2, 7));


    }
    SUBCASE("Test 10: throw exception when denominator is 0") {

        stringstream ss1("1/0");
        Fraction f_1;
        CHECK_THROWS(ss1 >> f_1);

        stringstream ss2("0/0");
        Fraction f_2;
        CHECK_THROWS(ss2 >> f_2);

        stringstream ss5("6/0");
        Fraction f_5;
        CHECK_THROWS(ss5 >> f_5);


    }
    SUBCASE("Test 11: throw exception when wrong char between numerator and denominator") {
        stringstream ss1("1@2");
        Fraction f_1;
        CHECK_THROWS(ss1 >> f_1);

        stringstream ss2("2.3");
        Fraction f_2;
        CHECK_NOTHROW(ss2 >> f_2);
    }

}

TEST_CASE("math operations between two fractions") {
    /**
     *  Fraction operator+(const Fraction &other) const;  // Addition
        Fraction operator-(const Fraction &other) const;  // Subtraction
        Fraction operator*(const Fraction &other) const;  // Multiplication
        Fraction operator/(const Fraction &other) const;  // Division
     */
    SUBCASE("Test 12: add two fractions") {
        Fraction f_1(-1, 2);
        Fraction f_2(1, 4);
        Fraction sum = f_1 + f_2;
        CHECK_EQ(sum, Fraction(-1, 4));


    }
    SUBCASE("Test 13: sub two fractions") {
        Fraction f_1(1, 2);
        Fraction f_2(1, 4);
        Fraction diff = f_1 - f_2;
        CHECK_EQ(diff, Fraction(1, 4));

        Fraction f_3(-1, 2);

        Fraction diff2 = f_2 - f_3;
        CHECK_EQ(diff2, Fraction(3, 4));


    }
    SUBCASE("Test 14: mul two fractions") {
        Fraction f1(2, 3);
        Fraction f2(3, 4);
        Fraction prod = f1 * f2;
        CHECK_EQ(prod, Fraction(1, 2));
    }
    SUBCASE("Test 15: div two fractions") {
        SUBCASE("sub test 15a: throw exception if denominator is 0") {
            Fraction f1(1, 2);
            Fraction f2(0, 1);
            CHECK_THROWS(f1 / f2);

        }
        SUBCASE("sub test 15b: not throw exception if denominator is not 0") {
            Fraction f1(1, 2);
            Fraction f2(1, 4);
            Fraction quotient = f1 / f2;
            CHECK_EQ(quotient, Fraction(2, 1));
        }
    }
}

TEST_CASE("math operations between farction and a float from the left") {
    /**
     * Fraction operator+(double value) const;           // Addition with a float value from the left
        Fraction operator-(double value) const;           // Subtraction with a float value from the left
        Fraction operator*(double value) const;           // Multiplication with a float value from the left
        Fraction operator/(double value) const;           // Division with a float value from the left
     */

    Fraction f_1(1, 2);
    SUBCASE("Test 16: add fraction and float") {


        Fraction sum = f_1 + 1.5;
        CHECK_EQ(sum, Fraction(5, 2));


    }
    SUBCASE("Test 17: sub fraction and float") {
        Fraction diff = f_1 - 1.5;
        CHECK_EQ(diff, Fraction(-3, 2));

    }
    SUBCASE("Test 18: mul fraction and float") {
        Fraction prod = f_1 * 1.5;
        CHECK_EQ(prod, Fraction(3, 4));

    }
    SUBCASE("Test 19: div fraction and float") {
        SUBCASE("sub test 19a: throw exception if denominator is 0") {

            CHECK_THROWS(f_1 / 0);

        }
        SUBCASE("sub test 19b: not throw exception if denominator is not 0") {
            Fraction quotient = f_1 / 1.5;
            CHECK_EQ(quotient, Fraction(1, 3));

        }
    }
}

TEST_CASE("math operations between farction and a float from the right") {
    /**
     * friend Fraction operator+(double value, const Fraction& fraction); //Addition with a float value from the right
        friend Fraction operator-(double value, const Fraction& fraction); //Subtraction with a float value from the right
        friend Fraction operator*(double value, const Fraction& fraction); //Multiplication with a float value from the right
        friend Fraction operator/(double value, const Fraction& fraction); //Division with a float value from the right
     */
    Fraction f_1(1, 2);
    SUBCASE("Test 20: add float and fraction") {


        Fraction sum = 1.5 + f_1;
        CHECK_EQ(sum, Fraction(5, 2));

    }
    SUBCASE("Test 21: sub float and fraction") {

        Fraction diff = 1.5 - f_1;
        CHECK_EQ(diff, Fraction(1, 1));

    }
    SUBCASE("Test 22: mul float and fraction") {

        Fraction prod = 1.5 * f_1;
        CHECK_EQ(prod, Fraction(3, 4));

    }
    SUBCASE("Test 23: div float and fraction") {
        SUBCASE("sub test 23a: throw exception if denominator is 0") {

            CHECK_THROWS(1.5 / f_1);
        }
        SUBCASE("sub test 23b: not throw exception if denominator is not 0") {
            Fraction quotient = 1.5 / f_1;
            CHECK_EQ(quotient, Fraction(3, 1));
        }
    }
}

TEST_CASE("math unary operations") {
/**
 *  Fraction &operator++();    // Prefix increment
        Fraction operator++(int);  // Postfix increment
        Fraction &operator--();    // Prefix decrement
        Fraction operator--(int);  // Postfix decrement
 */
    Fraction f_u_1(5 / 2);
    SUBCASE("Test 24: pre increment") {
        CHECK_NOTHROW(++f_u_1);
        CHECK_EQ(++f_u_1, Fraction(9, 2));
    }
    SUBCASE("Test 25: post increment") {
        CHECK_NOTHROW(f_u_1++);
        CHECK_EQ(f_u_1++, Fraction(11, 2));
    }
    SUBCASE("Test 26: pre decrement") {
        CHECK_NOTHROW(--f_u_1);
        CHECK_EQ(--f_u_1, Fraction(9, 2));

    }
    SUBCASE("Test 27: post decrement") {
        CHECK_NOTHROW(f_u_1--);
        CHECK_EQ(f_u_1--, Fraction(5, 2));

    }
}

TEST_CASE("comparsion operations with fractions") {

/**
 * bool operator==(const Fraction &other) const;  // Equality
        bool operator!=(const Fraction &other) const;  // Inequality
        bool operator>(const Fraction &other) const;   // Greater than
        bool operator>=(const Fraction &other) const;  // Greater than or equal to
        bool operator<(const Fraction &other) const;   // Less than
        bool operator<=(const Fraction &other) const;  // Less than or equal to
 */

    Fraction f_1(1, 2);
    Fraction f_2(2, 3);
    Fraction f_3(3, 4);
    SUBCASE("Test 28: equal") {
        CHECK(f_1 == f_1);
        CHECK(f_1 == Fraction(1, 2));
        CHECK(Fraction(1, 2) == f_1);
        CHECK_EQ(f_1 == f_2, false);

    }
    SUBCASE("Test 29: not equal") {
        CHECK(f_1 != f_2);
        CHECK(f_1 != f_3);
        CHECK(f_2 != f_3);
        CHECK(Fraction(1, 2) != f_3);
        CHECK(f_1 != Fraction(1, 3));
        CHECK_EQ(f_1 != f_1, false);

    }
    SUBCASE("Test 30: greater than") {
        CHECK(f_3 > f_2);
        CHECK_EQ(f_2 > f_3, false);
        CHECK(f_3 > f_1);

    }
    SUBCASE("Test 31: greater than or equal") {
        CHECK(f_3 >= f_2);
        CHECK(f_3 >= f_1);
        CHECK(f_2 >= f_1);
        CHECK_EQ(f_1 >= f_2, false);
        CHECK_EQ(f_1 >= f_3, false);
        CHECK_EQ(f_2 >= f_3, false);

    }
    SUBCASE("Test 32: less than") {
        CHECK(f_1 < f_2);
        CHECK(f_1 < f_3);
        CHECK(f_2 < f_3);
        CHECK_EQ(f_3 < f_2, false);
        CHECK_EQ(f_3 < f_1, false);
        CHECK_EQ(f_2 < f_1, false);

    }
    SUBCASE("Test 33: less than or equal") {
        CHECK(f_1 <= f_2);
        CHECK(f_1 <= f_3);
        CHECK(f_2 <= f_3);
        CHECK(f_1 <= f_1);
        CHECK(f_2 <= f_2);
        CHECK(f_3 <= f_3);
        CHECK_EQ(f_3 <= f_2, false);
        CHECK_EQ(f_3 <= f_1, false);
        CHECK_EQ(f_2 <= f_1, false);


    }
}

TEST_CASE("comparsion operations with float") {
    /**
     * bool operator==(double value) const;           // Equality with a float value
        bool operator!=(double value) const;           // Inequality with a float value
        bool operator>(double value) const;            // Greater than a float value
        bool operator<(double value) const;            // Less than a float value
        bool operator>=(double value) const;           // Greater than or equal to a float value
        bool operator<=(double value) const;           // Less than or equal to a float value
     */
    Fraction f_1(1, 2);
    SUBCASE("Test 34: equal") {
        SUBCASE("sub test 34a: equal from the left") {
            CHECK(f_1 == 0.5);
            CHECK_EQ(f_1 == 0.6, false);

        }
        SUBCASE("sub test 34b: equal from the right") {
            CHECK(0.5 == f_1);
            CHECK_EQ(0.6 == f_1, false);
        }
    }
    SUBCASE("Test 35: not equal") {
        SUBCASE("sub test 35a: not equal from the left") {
            CHECK(f_1 != 0.6);
            CHECK_EQ(f_1 != 0.5, false);

        }
        SUBCASE("sub test 35b: not equal from the right") {
            CHECK(0.6 != f_1);
            CHECK_EQ(0.5 != f_1, false);

        }
    }
    SUBCASE("Test 36: greater than") {
        SUBCASE("sub test 36a: greater than from the left") {
            CHECK(f_1 > 0.4);
            CHECK_EQ(f_1 > 0.5, false);

        }
        SUBCASE("sub test 36b: greater than from the right") {
            CHECK(1.0 > f_1);
            CHECK_EQ(0.5 > f_1, false);

        }
    }
    SUBCASE("Test 37: greater than or equal") {
        SUBCASE("sub test 37a: greater than or equal from the left") {
            CHECK(f_1 >= 0.4);
            CHECK(f_1 >= 0.5);
            CHECK_EQ(f_1 >= 0.6, false);

        }
        SUBCASE("sub test 37b: greater than or equal from the right") {
            CHECK(1.0 >= f_1);
            CHECK(0.5 >= f_1);
            CHECK_EQ(0.4 >= f_1, false);

        }
    }
    SUBCASE("Test 38: less than") {
        SUBCASE("sub test 38a: less than from the left") {
            CHECK(f_1 < 0.6);
            CHECK_EQ(f_1 < 0.5, false);

        }
        SUBCASE("sub test 38b: less than from the right") {
            CHECK(0.4 < f_1);
            CHECK_EQ(0.5 < f_1, false);

        }
    }
    SUBCASE("Test 39: less than or equal") {
        SUBCASE("sub test 39a: less than or equal from the left") {
            CHECK(f_1 <= 0.6);
            CHECK(f_1 <= 0.5);
            CHECK_EQ(f_1 <= 0.4, false);

        }
        SUBCASE("sub test 39b: less than or equal from the right") {
            CHECK(0.4 <= f_1);
            CHECK(0.5 <= f_1);
            CHECK_EQ(0.6 <= f_1, false);

        }
    }
}

TEST_CASE("output stream operator") {
    /**
     * friend ostream &operator<<(ostream &os, const Fraction &fraction); // Output stream
     */
    SUBCASE("Test 40: output stream straight forward") {
        stringstream ss_out;
        Fraction f_prnt(3, 4);
        CHECK_NOTHROW(ss_out << f_prnt);
        CHECK_EQ(ss_out.str(), "3/4");

    }
    SUBCASE("Test 41: output stream with negative denominator") {
        stringstream ss_out;
        Fraction f_prnt(-3, 4);
        CHECK_NOTHROW(ss_out << f_prnt);
        CHECK_EQ(ss_out.str(), "-3/4");

    }
    SUBCASE("Test 42: output stream with negative numerator") {
        stringstream ss_out;
        Fraction f_prnt(3, -4);
        ss_out << f_prnt;
        CHECK_EQ(ss_out.str(), "-3/4");

    }
    SUBCASE("Test 43: output stream with negative numerator and denominator") {
        stringstream ss_out;
        Fraction f_prnt(-3, -4);
        ss_out << f_prnt;
        CHECK_EQ(ss_out.str(), "3/4");

    }
    SUBCASE("Test 44: output stream with zero denominator") {
        stringstream ss_out;
        CHECK_THROWS(ss_out << Fraction(3, 0));



    }
    SUBCASE("Test 45: output stream with zero numerator") {
        stringstream ss_out;
        Fraction f_prnt(0, 4);
        ss_out << f_prnt;
        CHECK_EQ(ss_out.str(), "0/1");

    }
}

TEST_CASE("output stream with math operations") {
    /**
     * friend ostream &operator<<(ostream &os, const Fraction &fraction); // Output stream
     */

    Fraction f_1(1, 2);
    Fraction f_2(2, 3);
    Fraction f_3 = f_1 + f_2;
    Fraction f_4 = f_1 - f_2;
    Fraction f_5 = f_1 * f_2;
    Fraction f_6 = f_1 / f_2;
    SUBCASE("Test 46: output stream with add") {
        stringstream ss_out;
        ss_out << f_3;
        CHECK_EQ(ss_out.str(), "7/6");

    }
    SUBCASE("Test 47: output stream with sub") {
        stringstream ss_out;
        ss_out << f_4;
        CHECK_EQ(ss_out.str(), "-1/6");

    }
    SUBCASE("Test 48: output stream with mul") {
        stringstream ss_out;
        ss_out << f_5;
        CHECK_EQ(ss_out.str(), "1/3");

    }
    SUBCASE("Test 49: output stream with div") {
        stringstream ss_out;
        ss_out << f_6;
        CHECK_EQ(ss_out.str(), "3/4");


    }
}