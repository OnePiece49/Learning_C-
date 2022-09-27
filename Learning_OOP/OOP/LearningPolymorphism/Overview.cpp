#include <iostream>
#include <string>
using namespace std;

class people {
    public:
        people() {}

        people(string Name, int Age)
        : name(Name), age(Age) {}

        void show_name() {
            cout << "My people name : " << name << endl;
        }

        void set_name(string Name) {
            this->name = Name;
        }

    protected:
        string name;
        int age;
};

class wibu : public people {
    public:
        wibu(string Film)
        : film(Film) {}
    
        void show_name() {
            cout << "My wibu name : " << name << endl;
        }

    private:
        string film;

};



int main()
{
    wibu Vietdz("OnePiece");
    people *pViet = &Vietdz;
    pViet->set_name("Vietdz");
    pViet->show_name();
    return 0;
}