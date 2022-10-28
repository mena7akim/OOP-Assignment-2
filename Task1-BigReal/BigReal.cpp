#include "BigReal.h"


// Esraa

BigReal::BigReal(double realNumber) {

}

BigReal::BigReal(string realNumber) {

}

BigReal::BigReal(BigDecimalInt bigInteger) {

}

BigReal::BigReal(const BigReal &other) {

}

BigReal::BigReal(BigReal&& other) noexcept {

}

BigReal& BigReal::operator= (const BigReal& other) {

}

BigReal& BigReal::operator= (BigReal&& other) noexcept {

}





// Mina

BigReal BigReal::operator+ (const BigReal& other) const {

}

BigReal BigReal::operator- (const BigReal& other) const {

}





// Nervana

bool BigReal::operator< (const BigReal& anotherReal) const {

}

bool BigReal::operator> (const BigReal& anotherReal) const {

}

bool BigReal::operator== (const BigReal& anotherReal) const {

}

int BigReal::size() const {

}

int BigReal::sign() const {

}

ostream& operator << (ostream& out, BigReal num) {

}

istream& operator >> (istream& out, BigReal num) {

}


