#include <iostream>
#include <pthread.h>
using namespace std;

struct data {
    int *fd;
    string abc;
    
};

 void *hello(void *para) {
     struct data *abcd = (struct data *) para;
    cout << "Hello" << endl;
    return NULL;
}

class A {
    public:
        static int a;
                    struct data data1;  

        void threadHello() {
            pthread_t thread1;

            
            pthread_create(&thread1, NULL, hello, (void*) &data1);
        }
        // void hihi() {
        //     // A:: a = 10;
        //     cout << "hihi " << a << endl;
        //     hello();
        // }        
};

//int A:: a = 5;

int main()
{
   
    A Viet;
    Viet.threadHello();
    while(1);
    return 0;
    //Viet.hihi();
}