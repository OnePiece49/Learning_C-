#include <iostream>
#include <set>
#include <string>
using namespace std;

int main()
{
    set<string> linh_ngu {"hello", "heblo aeee", "Hello ae", "hihi"};
    set<string>:: iterator my_iterator = linh_ngu.begin();
    my_iterator = linh_ngu.upper_bound("hea");
    cout << *my_iterator << endl;
}