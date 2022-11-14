#include <iostream>
#include <functional>
#include "Function.h"
using namespace std;

int main() {
    simpleFunction f1([](double n) -> double { return n * n; });
    cout << "f1 = " << f1.evaluateAt(7) << endl;

    derivativeFunction f2(second, 7);
    cout << "f2 = " << f2.evaluateAt(11) << endl;

    compositionFunction f3(fun, cube);
    cout << "f3 = " << f3.evaluateAt(2) << endl;
    return 0;
}