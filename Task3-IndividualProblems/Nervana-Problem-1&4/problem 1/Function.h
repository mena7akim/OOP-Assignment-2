//
// Created by Nervana on 11/11/2022.
//
#include <iostream>
#include <functional>
#ifndef UNTITLED8_FUNCTION_H
#define UNTITLED8_FUNCTION_H
using namespace std;


class Function {
public:
    virtual double evaluateAt (double num) = 0;
};


class simpleFunction : public Function{
private:
    function<double (double n)> func;
public:
    simpleFunction(function<double (double n)> func2)
    {
        this->func = func2;
    }
    double evaluateAt (double number)
    {
        return func(number);
    }
};


class derivativeFunction : public Function{
private:
    function<double (double n)> func;
    double dx;

public:
    derivativeFunction(function<double (double n)> fun, double dx)
    {
        this -> func = fun;
        this -> dx = dx;
    }
    double evaluateAt(double num)
    {
        double result = ((func(num + dx)) - (func(num - dx))) / (2 * dx);
        return result;
    }
};


class compositionFunction
{
private:
    function<double (double n)> func1;
    function<double (double n)> func2;
public:
    compositionFunction(function<double(double n)>fun1, function<double (double n)> fun2)
    {
        this->func1 = fun1;
        this->func2 = fun2;
    }
    double evaluateAt(double num)
    {
        return func1(func2(num));
    }
};

double cube(double n) {
    return n * n * n;
}

double square (double n) {
    return n * n;
}

double second (double d) {
    return d * d - 5 * d - 4;
}

double fun (double d) {
    return d * d - 3 * d - 4;
}



#endif //UNTITLED8_FUNCTION_H
