#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string.h>
using namespace std;

int main() {
    string text;

    ifstream  MyFile("nvs.txt");
    
    ofstream MyData("Mydata.txt");

    getline (MyFile, text, '*');
    
    

    char *token = strtok((char *)text.c_str(), ",");
    for (int i = 0; i < text.size(); i++) {
          while( token != NULL ) {
            printf( " %s\n", token ); //In mỗi token ra
            token = strtok(NULL, ".");
            MyData << token;
            MyData << "\n";
            token = strtok(NULL, ",");
        }
    }


    MyFile.close();
}