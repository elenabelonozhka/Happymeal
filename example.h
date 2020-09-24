 
 /* Число вида a / b */
class Rational {
private:
    int a;
    int b;

public:
    static Rational FromNumbers(int c, int d);
};

class StaticValue {
public:
    static int value;
};

class Complex {
private:
    double re;
    double im;
    
public:
    Complex(double re = 0, double im = 0) :
        re(re),
        im(im)
    { }
    
    friend void PrintComplex(const Complex& c);
};
