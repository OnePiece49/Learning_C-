#include <iostream>
#include <list>
using namespace std;

/* insert List
int main()
{
    //list<int> my_list(5, 2, 5, 8, 9);  --> Sai
    list<int> my_list;
    my_list.push_back(110);
    my_list.push_back(20);
    my_list.push_back(35);
    list<int>:: iterator my_iterator = my_list.begin();
    my_iterator++;
    my_list.insert(my_iterator, 30);
    my_list.insert(my_iterator, 40);
    my_list.insert(my_iterator, 45);
    for(my_iterator = my_list.begin(); my_iterator != my_list.end(); my_iterator++) {
        cout << *my_iterator << endl;
    }
}
*/


/* earse List
int main()
{
    list<int> hello;
    hello.push_back(30);
    hello.push_back(45);
    hello.push_back(99);
    list<int>:: iterator my_iterator = hello.begin();
    hello.erase(my_iterator);
    my_iterator = hello.begin();
    cout << *(my_iterator) << endl;
}
*/

int main()
{
    list<int> hello;
    hello.push_back(30);
    hello.push_back(45);
    hello.push_back(99);
    hello.remove(30);
    cout << hello.front() << endl;
}