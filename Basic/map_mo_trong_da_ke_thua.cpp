#include <iostream>
using namespace std;

class A {
    public: 
        void print() {
            cout << "I'm class A" << endl;
        }  
        void hello() {
            cout << "hello" << endl;
        }
};

class B {
    public:
        void print() {
            cout << "I'm class B " << endl;
        }
};

class C : public A, public B {
    public:
        void print() {
            A::print();
        }
};

int main()
{
    C Vietpro;
    Vietpro.print();
}