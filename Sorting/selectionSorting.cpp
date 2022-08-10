/* Sap xep lua chon */
#include <iostream>
using namespace std;

void printArray(int array[], int n) {
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
        if (i == (n-1))
            cout <<"\n";
    }
}

void selectionSorting(int a[], int n) {
    for (int i = 0; i < n; i++) {
        int min_pos = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min_pos])
                min_pos = j;
        }
        swap(a[i], a[min_pos]);
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

    selectionSorting(array, number);
    printArray(array, number);
}