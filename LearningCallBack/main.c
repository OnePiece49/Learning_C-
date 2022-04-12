#include <iostream>
#include <pthread.h>

using namespace std;

int principalFn(char ch[], void (*ptr)(int))
{
    int id1 = 1;
    int id2 = 2;

    cout << "principal function: "<< id1 << endl;
    //    (*ptr)(id2);
    return id1;
}


void cb(int iden)
{
    cout<<"callback function"<<'\n';
}

int main()
{
    char cha[] = "and";
    principalFn(cha, cb);
    return 0;
}
