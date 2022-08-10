/* Sap xep noi boi*/

#include <iostream>
using namespace  std;

void printArray(int array[], int n) {
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
        if (i == (n-1))
            cout <<"\n";
    }
}

void bubbleSorting(int a[], int n) {
    for (int i = n - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (a[j] > a[j+1]) {
                swap(a[j], a[j+1]);
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

    bubbleSorting(array, number);
    printArray(array, number);
}
