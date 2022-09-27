#include <iostream>
#include <string>
using namespace std;

class create_people;
class people {
    public:
        people(const create_people &w);
        void get_info() {
            cout << "Name " << name << " and Age = " << age << " and Address " << address << endl;
        }
    private:
        string name;
        int age;
        int address;
};
class create_people {
    public:
        explicit create_people(const int &address) {
            cout << "Hello ae wibu: Address - " << this << endl; 
            _address = address;
        }
        create_people set_name(const string &name) {
            _name = name;
            return *this;
        }

        create_people& set_age(const int &age) {
            cout << "Hello huy ngu" << endl;
            _age = age;
            return *this;
        }
    private:
        string _name;
        int _age;
        int _address;
        friend class people;
};
people::people(const create_people &w)
    : name(w._name), age(w._age), address(w._address) {}

int main()
{
    create_people(123);
    people Vietdz = create_people(123).set_name("Vietdz")
                         .set_age(23);
    Vietdz.get_info();
    return 0;
}