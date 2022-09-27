#include <iostream>
#include <string>
using namespace std;    

class people {
    public:
        
        static void print_sth_ver3() {
            cout << "linh ngu vlon " << age << endl;
        }
        
        void get_static_age() {
            cout << "My Age is " << age << endl;
            age = 50;
            print_sth();
            print_sth_ver3();
        }


        static void print_sth_ver2() {
            cout << "Huy ngu vlon" << endl;
        }

        static void print_sth() {
            print_sth_ver2();
            cout << "I'm a static function " << age << endl;
        }

    private:
        string name;
        static int age; 
        const static int address = 23;
        
};

int people:: age = 23;

int main()
{
    people Vietdz;
    Vietdz.get_static_age();
    return 0;
}


