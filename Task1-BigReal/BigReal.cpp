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
    if(decPart.sign() != other.decPart.sign()){
        BigReal left = *this, right = other;
        if(decPart.sign()) {
            right.decPart.setSign('+');
            return left - right;
        }
        left.decPart.setSign('-');
        return right - left;
    }
    BigReal res = ((*this).fractionPart.size() > other.fractionPart.size() ? *this : other);
    int carry = 0;
    for(int i = min(res.fractionPart.size(), other.fractionPart.size()) - 1; i >= 0; i--){
        int x = (res.fractionPart[i] - '0') + (other.fractionPart[i] - '0') + carry;
        carry = (x > 9);
        res.fractionPart[i] = char(x % 10 + '0');
    }
    if(carry) res.decPart = res.decPart + other.decPart + BigDecimalInt("1");
    return res;
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


