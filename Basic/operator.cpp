#include <iostream>
using namespace std;

struct Complex {
    Complex( double r, double i ) 
        :re(r), im(i) 
    {}
   
   Complex operator+( Complex &other, Complex test );
   Complex operator=( Complex &other, Complex &otherb );
   void Display( ) {   cout << re << ", " << im << endl; }

    private:
        double re, im;
};

// Operator overloaded using a member function
Complex Complex::operator+( Complex &other ) {
   return Complex( re - other.re, im + other.im );
}

Complex Complex::operator=( Complex &other, Complex &otherb ) {
    this->im = other.im;
    this->re = other.re;
    return *this;
}

int main() {
   Complex a = Complex( 1.2, 3.4 );
   Complex b = Complex( 5.6, 7.8 );
   Complex c = Complex( 1.0, 5.0 );

   c.operator=(a+b);
   
   c.Display();
}