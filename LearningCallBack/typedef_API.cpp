#include <iostream>
#include <vector>
#include <string>
using namespace std;


typedef void (*MyFunc )(void *);
typedef struct {
    string method;
    string url;
    MyFunc func;
    void *parameter;
}s_api;



void print(void *a) {
    int *b = (int *)a;
    printf("Hello world %d\n", *b);
}

void hello(void *) {
    printf("Hello luong \n");
}

void hihi(vector<s_api *> &MyApi) {
    s_api *hi = new s_api;
    hi->method = "GET";

    MyApi.push_back(hi);
    cout << MyApi[0]->method << endl;
}

// void RegisterApi(string method, string url, void (*callback)(void *), void *para, int *number_api) {
//     int check = 5;
//     string method_http[5]{"GET", "POST", "PUT", "PATCH", "DELETE"};
//     for (int i = 0; i < 5; i++) {
//         if (method.compare(method_http[i]) == 0) {
//             if (callback == NULL) {
//                 cout << "Callback must be a function" << endl;
//                 return;
//             }

//             MyApi.push_back(s_api()); 
//             MyApi[*number_api].method = method;
//             MyApi[*number_api].url = url;
//             MyApi[*number_api].func = callback;
//             if(para != NULL) {
//                 MyApi[*number_api].parameter = para;
//             }
//             *number_api++;

//         } else {
//             check--;
//             if(check == 0) {
//                 cout << "Not Method Invalid" << endl;
//                 return;
//             }
//         }
//     }
// }

// void checkApi(string method, string url) {
//     for (int i = 0; i < MyApi.size(); i++) {
//         if (MyApi[i].method == method && MyApi[i].url == url) {
//             MyApi[i].func(MyApi[i].parameter);
//             return;
//         } 
//     }
//     cout << "None of API Regitered" << endl;
// }

int main()
{
    int a = 5;
    vector<s_api *> MyApi;
    hihi(MyApi);
    cout << MyApi[0]->method << endl;
    return 0;
}

