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
    this->reduce();
}

Fraction::Fraction(double value) {
    this->numerator = value * 1000;
    this->denominator = 1000;
    this->reduce();
}

/**
 * Arithmetic operators
 */

Fraction Fraction::operator+(const Fraction &other) const {
    int newNumerator = this->numerator * other.denominator + other.numerator * this->denominator;
    int newDenominator = this->denominator * other.denominator;
    this->reduce();
    return Fraction(newNumerator, newDenominator);
}

Fraction Fraction::operator-(const Fraction &other) const {
    int newNumerator = this->numerator * other.denominator - other.numerator * this->denominator;
    int newDenominator = this->denominator * other.denominator;
    this->reduce();
    return Fraction(newNumerator, newDenominator);
}

Fraction Fraction::operator*(const Fraction &other) const {
    int newNumerator = this->numerator * other.numerator;
    int newDenominator = this->denominator * other.denominator;
    this->reduce();
    return Fraction(newNumerator, newDenominator);
}

Fraction Fraction::operator/(const Fraction &other) const {
    //check if denominator is 0
    if (other.numerator == 0) {
        throw invalid_argument("Denominator can't be 0");
    }
    int newNumerator = this->numerator * other.denominator;
    int newDenominator = this->denominator * other.numerator;
    this->reduce();
    return Fraction(newNumerator, newDenominator);
}


/**
 * Arithmetic operators with double on the left
 */

/**
 * Arithmetic operators with double on the right
 */

/**
 * Comparison operators
 */


/**
 * Comparison operators with double
 */

/**
 * Increment and decrement operators
 */

Fraction &Fraction::operator++() {
    this->numerator += this->denominator;
    this->reduce();
    return *this;
}

Fraction &Fraction::operator--() {
    this->numerator -= this->denominator;
    this->reduce();
    return *this;
}

/**
 * Reduction functions
 */
 void Fraction::reduce() {// need to fix
    int gcd = __gcd(this->numerator, this->denominator);
    this->numerator /= gcd;
    this->denominator /= gcd;
    if (this->denominator < 0) {
        this->numerator *= -1;
        this->denominator *= -1;
    }
}

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}



