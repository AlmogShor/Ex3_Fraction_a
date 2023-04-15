//
// Description: Header file for the Fraction class
//

#pragma once

#include <iostream>

namespace ariel {

    class Fraction {
    public:
        // Constructors
        Fraction();                             // Default constructor
        Fraction(int numerator, int denominator); // Constructor with numerator and denominator
        Fraction(double value);                 // Constructor with value as a float

        // Arithmetic operators
        Fraction operator+(const Fraction& other) const;  // Addition
        Fraction operator-(const Fraction& other) const;  // Subtraction
        Fraction operator*(const Fraction& other) const;  // Multiplication
        Fraction operator/(const Fraction& other) const;  // Division
        Fraction operator+(double value) const;           // Addition with a float value
        Fraction operator-(double value) const;           // Subtraction with a float value
        Fraction operator*(double value) const;           // Multiplication with a float value
        Fraction operator/(double value) const;           // Division with a float value

        // Comparison operators
        bool operator==(const Fraction& other) const;  // Equality
        bool operator!=(const Fraction& other) const;  // Inequality
        bool operator>(const Fraction& other) const;   // Greater than
        bool operator<(const Fraction& other) const;   // Less than
        bool operator>=(const Fraction& other) const;  // Greater than or equal to
        bool operator<=(const Fraction& other) const;  // Less than or equal to
        bool operator==(double value) const;           // Equality with a float value
        bool operator!=(double value) const;           // Inequality with a float value
        bool operator>(double value) const;            // Greater than a float value
        bool operator<(double value) const;            // Less than a float value
        bool operator>=(double value) const;           // Greater than or equal to a float value
        bool operator<=(double value) const;           // Less than or equal to a float value

        // Increment and decrement operators
        Fraction& operator++();    // Prefix increment
        Fraction operator++(int);  // Postfix increment
        Fraction& operator--();    // Prefix decrement
        Fraction operator--(int);  // Postfix decrement

        // Input and output operators
        friend std::ostream& operator<<(std::ostream& os, const Fraction& fraction);  // Output
        friend std::istream& operator>>(std::istream& is, Fraction& fraction);        // Input

    private:
        int numerator;   // Numerator of the fraction
        int denominator; // Denominator of the fraction

        // Helper function to reduce the fraction to its simplest form
        void reduce();
    };

} // namespace ariel

