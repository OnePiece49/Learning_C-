#include <iostream>
#include <vector>
using namespace std;

// int main()
// {
//     vector<string> Mystring{"Huy ngu", "Viet vipppro"};
//     Mystring.pop_back();
//     cout<< Mystring.front() << endl;
    
//     // Mystring.push_back("Linh ml");
//     // for(int i = 0; i < Mystring.size(); i++) {
//     //     cout << Mystring.at(i) << endl;
//     // }
// }


/* test capacility and size of vector */
int main()
{
    std:: vector<int> array2 = { 9, 7, 5, 3, 1 };
        array2.reserve(20);
    array2 = {9, 10, 15};
    cout << array2.capacity() << " " << array2.size() << endl;
    array2.resize(10);
    array2.at(4) = 20;
    for(int i = 0; i < 5; i++) {
        cout << array2.at(i) << endl;
    }
}
//*/