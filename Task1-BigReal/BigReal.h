

#ifndef OOP_ASSIGNMENT_2_BIGREAL_H
#define OOP_ASSIGNMENT_2_BIGREAL_H

#include <bits/stdc++.h>
#include "BigDecimalIntClass.h"
using namespace std;

class BigReal {
    private:
        BigDecimalInt decPart;
        string fractionPart;
    public:
        explicit BigReal (double realNumber = 0.0); // Default constructor
        explicit BigReal (string realNumber);
        explicit BigReal (BigDecimalInt bigInteger);
        BigReal (const BigReal& other); // Copy constructor
        BigReal (BigReal&& other) noexcept ; // Move constructor
        BigReal& operator= (const BigReal& other); // Assignment operator
        BigReal& operator= (BigReal&& other) noexcept ; // Move assignment
        BigReal operator+ (const BigReal& other) const;
        BigReal operator- (const BigReal& other) const;
        bool operator< (const BigReal& anotherReal) const;
        bool operator> (const BigReal& anotherReal) const;
        bool operator== (const BigReal& anotherReal) const;
        int size() const;
        int sign() const;
        friend ostream& operator << (ostream& out, BigReal num);
        friend istream& operator >> (istream& out, BigReal num);
};


#endif
