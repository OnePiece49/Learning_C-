#include <iostream>
#include <vector>
using namespace std;


void selection_sorting(vector<int> &vt) { 
  int key = 0;
  for (int i = 0; i < vt.size(); i++) {
    key = i;
    for (int j = i + 1; j < vt.size(); j++) {
      if (vt.at(j) < vt.at(key)) {
        swap(vt.at(j), vt.at(key));
      }
    }
  }
}

int main()
{
  vector<int> my_array{1, 9, 2, -8, -4, 10, 58, 37, 99};
  selection_sorting(my_array);
  for (int i = 0; i < my_array.size(); i++) {
    cout << my_array.at(i) << " ";
  }
  return 0;
}
