#include "BigReal.h"


// Esraa


BigReal::BigReal(double realNumber)
{
    long long real=realNumber;
    *decPart= to_string(real);
    *fractionPart=to_string(realNumber-real);

}

BigReal::BigReal(string realNumber)
{
    string real;
    regex validInput("[-+]?[0-9]*[\\.]?[0-9]*");
    if( regex_match(realNumber, validInput))
    {
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
        *decPart=real;
        real.clear();
        for(long long i=(z+1);i<size;i++)
        {
            real+=realNumber[i];
        }
        *fractionPart=real;

    }
    else {
        cout << "invalid number";
        exit(1);
    }

}

BigReal::BigReal(BigDecimalInt bigInteger)
{
    *decPart=bigInteger;
    signNumber=bigInteger.sign();
    *fractionPart="0";

}

BigReal::BigReal(const BigReal &other)
{
    *decPart=*other.decPart;
    *fractionPart=*other.fractionPart;
    signNumber=other.signNumber;

}

BigReal::BigReal(BigReal&& other) noexcept
{
    //not * because we don't need save his place
    signNumber=other.signNumber;
    decPart=other.decPart;
    fractionPart=other.fractionPart;
    other.fractionPart= nullptr;
    other.decPart= nullptr;

}

BigReal& BigReal::operator= (const BigReal& other)
{
    *decPart=*other.decPart;
    signNumber=other.signNumber;
    *fractionPart=*other.fractionPart;

}

BigReal& BigReal::operator= (BigReal&& other) noexcept
{
    signNumber=other.signNumber;
    decPart=other.decPart;
    fractionPart=other.fractionPart;
    other.fractionPart= nullptr;
    other.decPart= nullptr;
}





// Mina

BigReal BigReal::operator+ (const BigReal& other) const {
    if(decPart->sign() != other.decPart->sign())
    {
        BigReal left = *this, right = other;
        if(decPart->sign()) {
            right.decPart->setSign('+');
            return left - right;
        }
        left.decPart->setSign('-');
        return right - left;
    }
    BigReal res = ((*this).fractionPart->size() > other.fractionPart->size() ? *this : other);
    int carry = 0;
    string fracPart1=res.fractionPart->getNumber(),fracPart2=other.fractionPart->getNumber();
    for(int i = min(res.fractionPart->size(), other.fractionPart->size()) - 1; i >= 0; i--)
    {

        int x =(fracPart1[i] - '0') + (fracPart2[i] - '0') + carry;
        carry = (x > 9);
        fracPart1[i] = char(x % 10 + '0');
    }
    if(carry)
        *res.decPart = *res.decPart + *other.decPart + BigDecimalInt("1");
    res.decPart->setSign((*this).size() ? '+' : '-');
    return res;
}

BigReal BigReal::operator- (const BigReal& other) const {
    BigReal left = *this, right = other;
    if((*this).sign() != other.sign()){
        if((*this).sign()){
            right.decPart->setSign('+');
            return left + right;
        }
        right.decPart->setSign('-');
        return left + right;
    }
    BigReal ret;
    left.decPart->setSign('+');
    left.decPart->setSign('-');
    if(*this == other) return ret;
    ret.decPart->setSign((*this).size() ? '+' : '-');
    if(fractionPart->size() > other.fractionPart->size())
    {
        *right.fractionPart = *right.fractionPart + BigDecimalInt(string(left.size() - right.size(), '0'));
    }
    else{
        *left.fractionPart = *left.fractionPart + BigDecimalInt(string(right.size() - left.size(), '0'));
    }
    if(left < right) {
        BigReal temp;
        temp = left;
        left = right;
        right = temp;
        ret.decPart->setSign((*this).size() ? '-' : '+');
    }
    *ret.fractionPart = string(left.size(), '0');
    string ret1=ret.fractionPart->getNumber(),rPart=right.fractionPart->getNumber(),lPart=left.fractionPart->getNumber();
    for(int i = left.fractionPart->size() - 1; i >= 0; i--){
        if(left.fractionPart[i] < right.fractionPart[i]){
            lPart[i - 1] -= 1;
            lPart[i] += 10;
        }
        ret1[i] = char(lPart[i] - '0' - rPart[i] - '0' + '0');
    }
    return ret;
}





// Nervana

bool BigReal::operator< (const BigReal& anotherReal) const {
    if (decPart.signNumber == '+' && anotherReal.decPart.signNumber == '+')
    {
        if(decPart!=anotherReal.decPart)
        {
            if (decPart < anotherReal.decPart)
                return true;
            else if(decPart > anotherReal.decPart)
                return false;
        }
        else if(decPart==anotherReal.decPart)
        {
            if(fractionPart<anotherReal.fractionPart)
                return true;
            else if(fractionPart>anotherReal.fractionPart)
                return false;
        }
    }
    else if (decPart.signNumber == '+' && anotherReal.decPart.signNumber == '-')
    {
        return false;
    }
    else if (decPart.signNumber == '-' && anotherReal.decPart.signNumber == '+')
    {
        return true;
    }
    else if (decPart.signNumber == '-' && anotherReal.decPart.signNumber == '-')
    {
        if (decPart != anotherReal.decPart)
        {
            if (decPart < anotherReal.decPart)
            {
                return false;
            }
            else if (decPart == anotherReal.decPart)
            {
                if(fractionPart < anotherReal.fractionPart)
                {
                    return false;
                }
                else if(fractionPart > anotherReal.fractionPart)
                {
                    return true;
                }
            }
        }
    }

}

bool BigReal::operator> (const BigReal& anotherReal) const {

}

bool BigReal::operator== (const BigReal& anotherReal) const {
    if ((decPart == anotherReal.decPart) && (fractionPart == anotherReal.fractionPart) && (decPart.signNumber == anotherReal.decPart.signNumber))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int BigReal::size() const {
    return fractionPart.size();
}

int BigReal::sign() const
{
    if (signNumber == '+')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

ostream& operator << (ostream& out, BigReal num) {
    if (num.signNumber == '+')
    {
        out << num.decPart;
    }
    else
    {
        if (num.decPart == "0")
        {
            out << num.decPart;
        }
        else
        {
            out << num.signNumber << num.decPart;
        }
    }
}

istream& operator >> (istream& out, BigReal num) {

}


