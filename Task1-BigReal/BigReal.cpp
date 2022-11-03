#include "BigReal.h"


// Esraa

BigReal::BigReal(double realNumber)
{
    int real=realNumber;
    decPart= to_string(real);
    double fraction=(realNumber-real);

}

BigReal::BigReal(string realNumber)
{
    regex validInput("[-+]?[0-9]+");
    if( regex_match(realNumber, validInput))
    {
        string real;
        int z=0;
        // setNumber(realNumber);
        if(realNumber[0] == '+')
        {
            realNumber.erase(0,1);
            signNumber = '+';
        }
        else if (realNumber[0] == '-')
        {
            realNumber.erase(0,1);
            signNumber = '-';
        }
        else
        {
            signNumber = '+';
        }
        long long size = realNumber.length();
        for(long long i=0;i<size;i++)
        {
            z=i;
            if(realNumber[i]!='.')
            {
                real += realNumber[i];
            }
            else
                break;
        }
        decPart=real;
        fractionPart="0";
        for(long long i=z;i<size;i++)
        {
            fractionPart+=realNumber[i];
        }

    }
    else
        cout<<"invalid number";

}

BigReal::BigReal(BigDecimalInt bigInteger) {

}

BigReal::BigReal(const BigReal &other)//عايزه اسال علي ال valid
{
    decPart=other.decPart;
    fractionPart=other.fractionPart;

}

BigReal::BigReal(BigReal&& other) noexcept
{
    decPart=other.decPart;
    fractionPart=other.fractionPart;
    // make empty other
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


