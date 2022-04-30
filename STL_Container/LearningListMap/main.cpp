#include <iostream>
#include <map>
using namespace std;


/*function check empty map
int main() {
    map<int, string> mymap, copymymap;
    mymap[0] = "a";
    mymap[1] = "b";
    mymap[0] = "c";

if (copymymap.empty()) cout << "copymymap is empty";
}
*/

/* map khởi tạo với string

int main() {
    map<string, int> A; // Khởi tạo một map A

    // Thêm vào map A một số phần tử.
    A["One"] = 1;
    A["Two"] = 2;
    A["Three"] = 3;

    // Duyệt và xuất ra từng cặp giá trị key: value của mỗi phần tử trong map A
    map<string, int>::iterator it;
    for (it = A.begin(); it != A.end(); it++) {
        cout << it->first.c_str() << ": " << it->second << endl;
    }

    // Thêm vào một phần tử giá trị key trùng lặp, chuyện gì sẽ xảy ra?
    A["One"] = 10;

    // In kết quả map A ra màn hình sau khi thêm vào 1 key trùng lặp,
    // tự chạy code xem kết quả của chính bạn.
    for (it = A.begin(); it != A.end(); it++) {
        cout << it->first << ": " << it->second << endl;
    }
}
*/

/* Truy xuất ptu trong mảng
int main()
{
    map<int, string> mymap, copymymap;
mymap[0] = "hello luong";
mymap[1] = "hello wibu";

cout << mymap[1] << " " << mymap.at(0);
}
*/

int main()
{
    map<string, int> myMap, mapInsert;
    myMap["Viet"] = 13;
    myMap["Long"] = 20;
    //myMap.insert (myMap.begin(), pair<string, int>("Huy", 5));
    //myMap.insert(pair<string, int>("Huy ngu", 5));
    myMap.insert (myMap.end(), pair<string, int>("Huy ngu", 5));
    map<string, int> :: iterator i;
    for (i = myMap.begin(); i != myMap.end(); i++) {
        cout << i->first << " : " << i->second << endl;
    }
}

// int main()
// {
//     map<int, char*> mymap, copymymap;
// mymap[0] = "a";
// mymap[1] = "b";
// mymap[5] = "c";

// // chèn vào copymymap cặp đối tượng (10, "c")	
// copymymap.insert(pair<int, char*>(10, "c"));

// // chèn (-1, "d") vào copymymap từ vị trí bắt đầu của copymymap
// copymymap.insert(copymymap.begin(), pair<int, char*>(-1, "d"));

// // chèn mymap vào copymymap
// map<int, char*> :: iterator i;
// copymymap.insert(mymap.begin(), mymap.end());
//     for (i = copymymap.begin(); i != copymymap.end(); i++) {
//         cout << i->first << " : " << i->second << endl;
//     }
// }