#include <iostream>
#include <pthread.h>
#include <stdio.h>
using namespace std;

int principalFn(char ch[], void (*ptr)(int, int))
{
    int id1 = 1;
    int id2 = 2;
    printf("%d", ptr);
    printf("%d\n", ptr);
    cout << "principal function: "<< id1 << endl;
    (*ptr)(id2, id1);
    return id1;
}

void cbcc(int iden, int hello)
{
    cout<<"callback function hello" << hello << iden << '\n';
}

void cb(int iden, int hello)
{
    cout<<"callback function" << hello << iden << '\n';
}

int main()
{
    char cha[] = "and";
    principalFn(cha, cbcc);
    return 0;
}
