#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool my_fun(int i, int j) {
    cout << i << " and " << j << endl;
    return abs(i) < abs(j);
}

int main()
{
    vector<int> array{-15, 15, 8,10, 7 ,31, 31, 8 , 7, -15};
    sort(array.begin(), array.end(), my_fun);
    for (auto i : array) {
        cout << i << " ";
    }
}

