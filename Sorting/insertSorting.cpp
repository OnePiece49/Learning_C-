/* Sap xep chen */
#include <iostream>
#include <vector>
using namespace std;

void printArray(int array[], int n) {
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
        if (i == (n-1))
            cout <<"\n";
    }
}

void insert_sorting(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int temp = a[i];
        for (int j = 0; j < i; j++) {
            if (a[j] > temp) {
                swap(a[i], a[j]);
            }
        }
        printArray(a, n);
    }
}   

int main()
{
    int array[1000] = {0};
    int number = 0;
    cout << "Enter number elements in array: ";
    cin >> number;
    cout << "Enter index of elements: ";
    for (int i = 0; i < number; i++) {
        cin >> array[i];
    }

    insert_sorting(array, number);
    printArray(array, number);
}