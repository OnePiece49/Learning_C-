#include <iostream>
#include <memory>

using namespace std;

/* ptr_unique 
class Rectangle {
    int length;
    int breadth;
 
public:
    Rectangle(int l, int b){
        length = l;
        breadth = b;
    }
 
    int area(){
        return length * breadth;
    }
};
 
int main(){
 
    unique_ptr<Rectangle> P1(new Rectangle(10, 5));
    cout << P1->area() << endl; // This'll print 50
 
    // unique_ptr<Rectangle> P2(P1);
    unique_ptr<Rectangle> P2;
    P2 = move(P1);
 
    // This'll print 50
    cout << P2->area() << endl;
    cout << P1->area() << endl;
    // cout<<P1->area()<<endl;
    return 0;
}
*/



/* shared_ptr */
class Rectangle {
    int length;
    int breadth;
 
public:
    Rectangle(int l, int b)
    {
        length = l;
        breadth = b;
    }
 
    int area()
    {
        return length * breadth;
    }
};
 
int main()
{
 
    shared_ptr<Rectangle> P1(new Rectangle(10, 5));
    // This'll print 50
    cout << P1->area() << endl;
 
    shared_ptr<Rectangle> P2;
    P2 = P1;
 
    // This'll print 50
    cout << P2->area() << endl;
 
    // This'll now not give an error,
    cout << P1->area() << endl;
 
    // This'll also print 50 now
    // This'll print 2 as Reference Counter is 2
    cout << P1.use_count() << endl;
    cout << P2.use_count() << endl;
    return 0;
}


/* Sử dụng tài nguyên * trong smart_poiter
struct Fraction
{
	int m_numerator = 0;
	int m_denominator = 1;

	Fraction(int numerator = 0, int denominator = 1) :
		m_numerator(numerator), m_denominator(denominator)
	{
	}
};


int main()
{
	// Create a single dynamically allocated Fraction with numerator 3 and denominator 5
	std::unique_ptr<Fraction> f1 = std::make_unique<Fraction>(3, 5);
	std::cout << (*f1).m_numerator << "/" << (*f1).m_denominator << std::endl;

	// Create a dynamically allocated a Fraction here
	// We can also use automatic type deduction to good effect here
	auto f2 = std::make_unique<Fraction>(4, 6);
	std::cout << (*f2).m_numerator << "/" << (*f2).m_denominator << std::endl;

	return 0;
}
*/


 
// struct Resource
// {
// public:
// 	Resource() { std::cout << "Resource acquired\n"; }
// 	~Resource() { std::cout << "Resource destroyed\n"; }
// };
 
// int main()
// {
// 	// allocate a Resource object and have it owned by std::shared_ptr
// 	Resource *res = new Resource;
//     Resource hello;
// 	std::shared_ptr<Resource> ptr1(res);
// 	{
// 		std::shared_ptr<Resource> ptr2(ptr1); // use copy initialization to make another std::shared_ptr pointing to the same thing
 
// 		std::cout << "Killing one shared pointer\n";
// 	} // ptr2 goes out of scope here, but nothing happens
 
// 	std::cout << "Killing another shared pointer\n";
 
// 	return 0;
// } 
