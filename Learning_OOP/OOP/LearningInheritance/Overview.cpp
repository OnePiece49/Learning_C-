#include <iostream>
#include <string>
using namespace std;

class people {
    public:
        people() {}

        people(string Name, int Age)
        : name(Name), age(Age) {}

        void get_name() {
            cout << "My name: " << name << endl;
        }

    protected:
        string name;
        int age;
};

class wibu : private people {
    public:
        wibu(string Film)
        : film(Film) {}
    
    void update_age(int Age) {
        this->age = Age;
    }

    void get_age() {
        cout << "My age is " << age << endl;
    }
    
    void get_film() {
        cout << "My favourite film is " << film << endl;
    }

    private:
        string film;

};



int main()
{
    wibu Viet("OnePiece");
    Viet.get_film();
    Viet.update_age(45);
    Viet.get_age();
    return 0;
}