//
// Created by shora on 15/04/2023.
//

#include "Fraction.hpp"
#include <iostream>

using namespace std;
using namespace ariel;

//Ctors

Fraction::Fraction() {
    this->numerator = 0;
    this->denominator = 1;
}

Fraction::Fraction(int numerator, int denominator) {
    if (denominator == 0) {
        throw invalid_argument("Denominator can't be 0");
    }
    this->numerator = numerator;
    this->denominator = denominator;
    reduce();
}

Fraction::Fraction(double value) {
    this->numerator = value * 1000;
    this->denominator = 1000;
    reduce();
}

/**
 * Arithmetic operators
 */

Fraction Fraction::operator+(const Fraction &other) const {
    int newNumerator = this->numerator * other.denominator + other.numerator * this->denominator;
    int newDenominator = this->denominator * other.denominator;
    return Fraction(newNumerator, newDenominator);
}

Fraction Fraction::operator-(const Fraction &other) const {
    int newNumerator = this->numerator * other.denominator - other.numerator * this->denominator;
    int newDenominator = this->denominator * other.denominator;
    return Fraction(newNumerator, newDenominator);
}

Fraction Fraction::operator*(const Fraction &other) const {
    int newNumerator = this->numerator * other.numerator;
    int newDenominator = this->denominator * other.denominator;
    return Fraction(newNumerator, newDenominator);
}

Fraction Fraction::operator/(const Fraction &other) const {
    //check if denominator is 0
    if (other.numerator == 0) {
        throw invalid_argument("Denominator can't be 0");
    }
    int newNumerator = this->numerator * other.denominator;
    int newDenominator = this->denominator * other.numerator;
    return Fraction(newNumerator, newDenominator);
}

