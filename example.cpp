 
#include <iostream>
#include "example.h"

using namespace std;

int StaticValue::value = 5;

Rational Rational::FromNumbers(int c, int d) {
    Rational result;

    result.a = c;
    result.b = d;
    
    // a = c;
    
    return result;
}

int Square(int x) {
    return x * x;
}

double Square(double x) {
    return x * x;
}

void PrintComplex(const Complex& c) {
    cout << "(" << c.re << ", " 
         << c.im << ")" << endl;
}

int main() {
    Rational res;
    
    res = Rational::FromNumbers(1, 2);
    
    Rational res2;
    
    res2 = res.FromNumbers(3, 4);
    
    StaticValue sv1;
    StaticValue sv2;
    
    cout << "Value = " << StaticValue::value << endl;
    cout << "sv1.value = " << sv1.value << endl;
    
    StaticValue::value = 8;
    
    cout << "Value = " << StaticValue::value << endl;
    cout << "sv1.value = " << sv1.value << endl;
    
    
    sv1.value = 10;

    cout << "Value = " << StaticValue::value << endl;
    cout << "sv1.value = " << sv1.value << endl;
    cout << "sv2.value = " << sv2.value << endl;
    
    cout << Square(5) << endl;
    cout << Square(3.14) << endl;
    
    Complex c(10, 3.14);
    
    PrintComplex(c);

    return 0;
}
