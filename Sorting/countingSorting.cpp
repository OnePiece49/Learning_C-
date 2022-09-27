/* 
    Sắp xếp đếm phân phối 
        Ta luôn có kích thước của mảng tối đa chứa 10^7 phần tử, nếu khai báo int arr[10^7 + 10] có thể gây ra tràn bộ nhớ stack
*/ 

#include <iostream>
#include <algorithm>
using namespace std;

int arr[10000000] = {0};

int main()
{
    int arr_enter[1000] = {0};
    int number = 0;
    int m = 0;

    cout << "Enter number elements in array: ";
    cin >> number;
    cout << "Enter index of elements: ";
    for (int i = 0; i < number; i++) {
        cin >> arr_enter[i];
        arr[arr_enter[i]]++;
        m = max(arr_enter[i], m);
    }

    for (int i = 0; i < m + 1; i++) {
        if (arr[i] != 0) {
            for (int j = 0; j < arr[i]; j++) {
                cout << i << " ";
            }
        }
    }
    return 0;
}