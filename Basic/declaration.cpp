#include <iostream>
using namespace std;

int *fun(void) {
    int *a = (int *)malloc(sizeof(int));
    *a = 20;
    return a;
}

int fun_test(void) {
    int a = 155;
    return a;
}

int main()
{  
    /* int *array[20] */
    int *arr[20];
    int test = 5;
    arr[0] = &test;
    cout << *arr[0] << endl;

    /* int (*array)[20] */
    int (*array)[20];
    int a[20] = {9, 3, 8};
    array = &a; 
    cout << *(array[0]) << endl;

    /* int *fun(void) */
    int fun_print = *fun();
    cout << fun_print << endl;


    /* int (*fun)(void) */
    int (*fun)(void);
    fun = &fun_test;
    int print_funpointer = (*fun)();
    print_funpointer = fun();
    cout << print_funpointer << endl;

    return 0;
}