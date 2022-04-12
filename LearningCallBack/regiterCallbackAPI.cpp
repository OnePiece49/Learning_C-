#include "iostream"
#include <string>
#include <stdio.h>
using namespace std;

string MethodReister;

int RegisterAPI(string method, string url, string nameFunction, void *parameter) {
    int check = 5;
    string method_http[5]{"GET", "POST", "PUT", "PATCH", "DELETE"};
    
    for (int i = 0; i < 5; i++) {
        if (method.compare(method_http[i]) == 0) {
            MethodReister.append("{");                  //{
            MethodReister.append("\"");                 // "
            MethodReister.append("METHOD");             // METHOD
            MethodReister.append("\"");                 // "
            MethodReister.append(":");                  // :
            MethodReister.append("\"");                 // "
            MethodReister.append(method);               // GET    
            MethodReister.append("\"");                 // "

            MethodReister.append(",");                  // ,
            MethodReister.append("\"");                 // "
            MethodReister.append("URL");                // URL
            MethodReister.append("\"");                 // "
            MethodReister.append(":");                  // :
            MethodReister.append("\"");                 // "
            MethodReister.append(url);                  // link    
            MethodReister.append("\"");                 // "
            MethodReister.append(",");                  // ,

            MethodReister.append("\"");                 // "
            MethodReister.append("CALLBACK");           // CALLBACK
            MethodReister.append("\"");                 // "
            MethodReister.append(":");                  // :
            MethodReister.append("\"");                 // "
            MethodReister.append(nameFunction));        // FUNCTION CALLBACK    
            MethodReister.append("\"");                 // "
            MethodReister.append(",");                  // ,

            MethodReister.append("\"");                 // "
            MethodReister.append("parameter");          // CALLBACK
            MethodReister.append("\"");                 // "
            MethodReister.append(":");                  // :
            MethodReister.append("\"");                 // "
            MethodReister.append(addParameter);         // FUNCTION CALLBACK    
            MethodReister.append("\"");                 // "
            MethodReister.append(",");                  // ,
            break;
        } else {
            check--;
            if(check == 0) {
                cout << "Not Method Invalid" << endl;
                return 1;
            }
        }
    }
}


void print() {
    cout << "hello" << endl;
}

void *print2() {
    cout << "hello2" << endl;
}

int main()
{
        int a = 5;
        string addParameter = static_cast<string>(&a);
            MethodReister.append("{");                  //{
            MethodReister.append("\"");                 // "
            MethodReister.append("METHOD");             // METHOD
            MethodReister.append("\"");                 // "
            MethodReister.append(":");                  // :
            MethodReister.append("\"");                 // "
            MethodReister.append("GET");               // GET    
            MethodReister.append("\"");                 // "

            MethodReister.append(",");                  // ,
            MethodReister.append("\"");                 // "
            MethodReister.append("URL");                // URL
            MethodReister.append("\"");                 // "
            MethodReister.append(":");                  // :
            MethodReister.append("\"");                 // "
            MethodReister.append("local");                  // link    
            MethodReister.append("\"");                 // "
            MethodReister.append(",");                  // ,

            MethodReister.append("\"");                 // "
            MethodReister.append("CALLBACK");           // CALLBACK
            MethodReister.append("\"");                 // "
            MethodReister.append(":");                  // :
            MethodReister.append("\"");                 // "
            MethodReister.append("printf");        // FUNCTION CALLBACK    
            MethodReister.append("\"");                 // "
            MethodReister.append(",");                  // ,

            MethodReister.append("\"");                 // "
            MethodReister.append("parameter");           // CALLBACK
            MethodReister.append("\"");                 // "
            MethodReister.append(":");                  // :
            MethodReister.append("\"");                 // "
            MethodReister.append(addParameter);        // FUNCTION CALLBACK    
            MethodReister.append("\"");                 // "
            MethodReister.append(",");                  // ,
            MethodReister.append("}");    
    }
