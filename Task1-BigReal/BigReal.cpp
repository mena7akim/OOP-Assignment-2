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
    res.decPart.setSign((*this).size() ? '+' : '-');
    return res;
}

BigReal BigReal::operator- (const BigReal& other) const {
    BigReal left = *this, right = other;
    if((*this).sign() != other.sign()){
        if((*this).sign()){
            right.decPart.setSign('+');
            return left + right;
        }
        right.decPart.setSign('-');
        return left + right;
    }
    BigReal ret;
    left.decPart.setSign('+');
    left.decPart.setSign('-');
    if(*this == other) return ret;
    ret.decPart.setSign((*this).size() ? '+' : '-');
    if(fractionPart.size() > other.fractionPart.size()) {
        right.fractionPart = right.fractionPart + string(left.size() - right.size(), '0');
    }
    else{
        left.fractionPart = left.fractionPart + string(right.size() - left.size(), '0');
    }
    if(left < right) {
        BigReal temp;
        temp = left;
        left = right;
        right = temp;
        ret.decPart.setSign((*this).size() ? '-' : '+');
    }
    ret.fractionPart = string(left.size(), '0');
    for(int i = left.fractionPart.size() - 1; i >= 0; i--){
        if(left.fractionPart[i] < right.fractionPart[i]){
            left.fractionPart[i - 1] -= 1;
            left.fractionPart[i] += 10;
        }
        ret.fractionPart[i] = char(left.fractionPart[i] - '0' - right.fractionPart[i] - '0' + '0');
    }
    return ret;
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


