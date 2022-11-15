#include "BigReal.h"


// Esraa

BigReal::BigReal(double realNumber)
{
    long long real = realNumber; // 0.65463
    string temp = to_string(real);
    if(temp[0] == '+' || temp[0] == '-') {
        signNumber = temp[0];
        temp.erase(temp.begin());
    }
    else{
        signNumber = '+';
    }
    *decPart = BigDecimalInt(temp);
    temp = to_string(realNumber - (double)real);
    string s = "";
    bool found = 0;
    for(int i = 0; i < temp.size(); i++){
        if(temp[i] == '.') found = 1;
        if(found) s += temp[i];
    }
    if(s[0] == '.') s.erase(s.begin());
    *fractionPart = BigDecimalInt(s);
}

BigReal::BigReal(string realNumber)
{
    string real;
    regex validInput("[-+]?[0-9]*[\\.]?[0-9]*");
    if(regex_match(realNumber, validInput))
    {
        int z=0;
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
        for(long long i = 0; i < size; i++)
        {
            z = i;
            if(realNumber[i]!='.')
            {
                real += realNumber[i];
            }
            else
                break;
        }
        *decPart = BigDecimalInt(real);
        real.clear();
        for(long long i=(z+1);i<size;i++)
        {
            real+=realNumber[i];
        }
        *fractionPart = BigDecimalInt(real);

    }
    else {
        cout << "invalid number";
        exit(1);
    }

}

BigReal::BigReal(BigDecimalInt bigInteger)
{
    *decPart = bigInteger;
    signNumber = bigInteger.sign();
    *fractionPart="0";
}

BigReal::BigReal(const BigReal &other)
{
    *decPart = *other.decPart;
    *fractionPart = *other.fractionPart;
    signNumber = other.signNumber;

}

BigReal::BigReal(BigReal&& other) noexcept
{
    //not * because we don't need save his place

    signNumber = other.signNumber;
    decPart = other.decPart;
    fractionPart = other.fractionPart;
    other.fractionPart= nullptr;
    other.decPart= nullptr;

}

BigReal& BigReal::operator= (const BigReal& other)
{
    *decPart = *other.decPart;
    signNumber = other.signNumber;
    *fractionPart = *other.fractionPart;
    return *this;
}

BigReal& BigReal::operator= (BigReal&& other) noexcept
{
    if(this != &other) {
        delete[] decPart;
        delete[] fractionPart;
        signNumber = other.signNumber;
        decPart = other.decPart;
        fractionPart = other.fractionPart;
        other.fractionPart = nullptr;
        other.decPart = nullptr;
    }
    return *this;
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

    BigDecimalInt left = *(this->fractionPart), right = *(other.fractionPart);

    // make the two fraction the same size
    if(left.size() > right.size()) right = BigDecimalInt(right.getNumber() + string(left.size() - right.size(), '0'));
    else left = BigDecimalInt(left.getNumber() + string(right.size() - left.size(), '0'));
    BigDecimalInt fractionAddition = left + right;

    left = *(this->decPart), right = *(other.decPart);
    BigDecimalInt decAddition = left + right;
    // if there was a carry from the fraction addition
    if(fractionAddition.size() > max((*(this->fractionPart)).size(), (*(other.fractionPart)).size())){
        decAddition = decAddition + BigDecimalInt("1"); // add 1 to the decimal part
        string temp = fractionAddition.getNumber();
        temp.erase(temp.begin()); // delete the carry from the fraction part
        fractionAddition = BigDecimalInt(temp);
    }

    BigReal ret;
    *(ret.decPart) = decAddition;
    *(ret.fractionPart) = fractionAddition;
    ret.signNumber = (*this).signNumber;
    return ret;
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

    if(*this == other) return BigReal("0");

    left.signNumber = 1;
    right.signNumber = 1;

    if(left < right) swap(left, right);

    BigDecimalInt decSubtraction, fractionSubtraction;

    // make the two fraction the same size
    if(left.size() > right.size()) *(right.fractionPart) = BigDecimalInt((*(right.fractionPart)).getNumber() + string(left.size() - right.size(), '0'));
    else *(left.fractionPart) = BigDecimalInt((*(left.fractionPart)).getNumber() + string(right.size() - left.size(), '0'));


    // get one from the decimal part if the fraction part of the bigger number is less than the fraction part of the lower number
    if(*(left.fractionPart) < *(right.fractionPart)){
        *(left.decPart) = *(left.decPart) - BigDecimalInt("1");
        string temp = (*(left.fractionPart)).getNumber();
        temp[0] += 10;
        (left.fractionPart)->setNumber(temp);
    }

    fractionSubtraction = *(left.fractionPart) - *(right.fractionPart);
    decSubtraction = *(left.decPart) - *(right.decPart);

    // removing leading zeros
    string temp = decSubtraction.getNumber(), s = "";
    bool found = 0;
    for(int i = 0; i < temp.size(); i++){
        if(temp[i] != '0') found = 1;
        if(found) s += temp[i];
    }
    decSubtraction = BigDecimalInt(s);

    BigReal ret;
    *(ret.decPart) = decSubtraction;
    *(ret.fractionPart) = fractionSubtraction;
    ret.signNumber = (*this > other ? (*this).signNumber : other.signNumber);
    return ret;
}





// Nervana

bool BigReal::operator< (const BigReal& anotherReal) const
{
    if (this->signNumber == '+' && anotherReal.signNumber == '+')
    {
        if (decPart != anotherReal.decPart)
        {
            if (decPart < anotherReal.decPart)
            {
                return true;
            }
            else if (decPart > anotherReal.decPart)
            {
                return false;
            }
        }
        else if (decPart == anotherReal.decPart)
        {
            if (fractionPart < anotherReal.fractionPart)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
    else if (this->signNumber== '+' && anotherReal.signNumber == '-')
    {
        return false;
    }
    else if (this->signNumber == '-' && anotherReal.signNumber == '+')
    {
        return true;
    }
    else if (this->signNumber == '-' && anotherReal.signNumber == '-')
    {
        if (decPart != anotherReal.decPart)
        {
            if (decPart < anotherReal.decPart)
            {
                return false;
            }
            else if (decPart > anotherReal.decPart)
            {
                return true;
            }
        }
        else if (decPart == anotherReal.decPart)
        {
            if (fractionPart < anotherReal.fractionPart)
            {
                return false;
            }
            else
            {
                return true;
            }
        }
    }
}

bool BigReal::operator> (const BigReal& anotherReal) const
{
    if(!(*this == anotherReal) && !(*this < anotherReal)) return 1;
    return 0;
}

bool BigReal::operator== (const BigReal& anotherReal) const
{
    if ((decPart == anotherReal.decPart) && (fractionPart == anotherReal.fractionPart) && (this->signNumber == anotherReal.signNumber))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int BigReal::size() const
{
    return (*fractionPart).size() + (*decPart).size();
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

ostream& operator << (ostream& out, BigReal num)
{
    if (num.signNumber == '+')
    {
        out << num.decPart << "." << num.fractionPart;
    }
    else
    {
        out << num.signNumber << num.decPart << "." << num.fractionPart;
    }
    return out;
}

istream& operator >> (istream& in, BigReal num)
{

}


