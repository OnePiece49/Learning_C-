#include <iostream>
#include <map>
#include <memory>
using namespace std;

// int main()
// {
//     pair<string, int>huy_ngu;
//     huy_ngu.first = "huy ngu";
//     huy_ngu.second = 567;
//     cout << huy_ngu.first << huy_ngu.second << endl;
// }

// int main()
// {
//     pair<map<string, int>, string> huy_ngu;
//     huy_ngu.first["ngu vl"] = 123;
//     huy_ngu.second = "vlon";
//     cout << huy_ngu.first["ngu vl"] << endl; 
// }

const shared_ptr<string> huy_ngu() {
    return shared_ptr<string>(new string("dm thang huy ngu vkl"));
}

int main()
{
    shared_ptr<string>than_ngu(new string("than ngu vkl"));
    cout << (*than_ngu) << endl;
    cout << *huy_ngu() << endl;
    //map<map<string, int>, string> huy_ngu;
    // huy_ngu.["huy ngu"] = 5;
}