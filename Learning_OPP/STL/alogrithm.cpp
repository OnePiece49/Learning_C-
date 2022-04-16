#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/* sort loai 1
int main()
{
    int arr[] = {1, 3, 9, 0, 9,8, -5, 9, 20};
    sort(arr + 1, arr + 7);
    for(int i = 0; i < sizeof(arr) / sizeof(int); i++) {
        cout << arr[i] << " ";
    }
}
*/

/* sort với vector 
bool compare(int a, int b) {
	return true;
}

int main()
{
    vector<int> arr = {9, 25, -1 , 30, 35, 88};
    sort(arr.begin(), arr.end() - 5);
    for(int i = 0; i < sizeof(arr) / sizeof(int); i++) {
        cout << arr[i] << " ";
    }
}

*/

/* binary_search 
int main()
{
    int arr[] = {9, 9, -5, 0, 17, -8};
    sort(arr, arr + 6);
    if (binary_search(arr, arr + 9, -5) ) {
        cout << "yes";
    } else {
        cout << "no";
    }
} 
*/

bool function(int a) {
    return a % 2;
}

int main()
{
    vector<int> arr = {9, 8, 20, 31, 35, -6, 7};

    partition(arr.begin(), arr.end(), [](int x) { return x % 2;});
    for(int i = 0; i < sizeof(arr) / sizeof(int) + 1; i++) {
        cout << arr[i] << " ";
    }
}

