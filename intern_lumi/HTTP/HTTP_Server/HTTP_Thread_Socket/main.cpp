#include "lib/http.hpp"
#include "lib/registerAPI.hpp"
#include <iostream>
using namespace std;




void respond(void *) {
    //cout << "respond func" << endl;
    Http:: SendHttpRespond(&Myserver);
}

void respond_hello(void *) {
    cout << "respond func" << endl;
    Http:: SendHttpRespond(&Myserver);
}

int main()
{
    int a = 0;
    
    MyApi:: RegisterApi("GET", "/", respond, NULL, &a, Myserver.MyApi);
    MyApi:: RegisterApi("GET", "/data", respond_hello, NULL, &a, Myserver.MyApi);
    Http:: InitHttp(&Myserver, 7000);
    cout << a << endl;
    while (1)
    {   
        s_fdserver Myserver;
        Myserver.fd_data = Http:: AcceptConnect(&Myserver);
    }
}