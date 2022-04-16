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

vector<s_api> MyApi;

void print(void *a) {
    int *b = (int *)a;
    printf("Hello world %d\n", *b);
}

void hello(void *) {
    printf("Hello luong \n");
}

void RegisterApi(string method, string url, void (*callback)(void *), void *para, int *number_api, vector<s_api *> &MyApi) {
    int check = 5;
    string method_http[5]{"GET", "POST", "PUT", "PATCH", "DELETE"};
    for (int i = 0; i < 5; i++) {
        if (method.compare(method_http[i]) == 0) {
            if (callback == NULL) {
                cout << "Callback must be a function" << endl;
                return;
            }
            s_api *newAPI = new s_api;
            
            newAPI->method = method;
            newAPI->url = url;
            newAPI->func = callback;
            if(para != NULL) {
                newAPI->parameter = para;
            }
            MyApi.push_back(newAPI); 
            (*number_api)++;

        } else {
            check--;
            if(check == 0) {
                cout << "Not Method Invalid" << endl;
                return;
            }
        }
    }
}

void checkApi(string method, string url, vector<s_api *> MyApi) {
    for (int i = 0; i < MyApi.size(); i++) {
        if (MyApi[i]->method == method && MyApi[i]->url == url) {
            MyApi[i]->func(MyApi[i]->parameter);
            return;
        } 
    }
    cout << "None of API Regitered" << endl;
}

int main()
{
    int a = 5;
    int number_api = 0;
    vector<s_api *> MyApi;
    RegisterApi("GET", "localhost", print, (void *)&a, &number_api, MyApi);
    RegisterApi("POST", "hihi", hello, (void *)&a, &number_api, MyApi);

    RegisterApi("PUT", "vcl", hello, NULL, &number_api, MyApi);
    cout << MyApi[0]->method << endl;
    cout << MyApi[1]->method << endl;
    checkApi("POST", "hihi", MyApi);
    cout << number_api << endl;
    return 0;
}

