#include <iostream>
#include <map>
#include <vector>
#include <list>
using namespace std;
int main()
{
    std::vector<int> my_vec;
    for(int i = 3; i < 10; i++) {
        my_vec.push_back(i);
    }
    vector<int> :: iterator my_iterator = my_vec.end();
    for(my_iterator = my_vec.begin(); my_iterator != my_vec.end(); my_iterator++) {
        cout << *my_iterator << endl;
    }
}