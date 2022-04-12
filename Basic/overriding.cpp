#include <iostream>
#include <string>
using namespace std;

class people {
    protected:
        string Name;
        int Age;

    public:
        people(string name, int age) 
            :Name(name), Age(age)
        {}
        people() {
            cout << "Hello world" << endl;
        }

        virtual void printAge() {
            cout << " Tuoi cua " << Name << ": " << Age << endl;
        }
};

class wibu : public people{
    public:
        wibu(string name, int age, string Film) 
            :people(name, age), film(Film)
        {}

        void printAge() override {
            cout << " Tuoi  " << Name << ": " << Age << endl;
        }

        void printName() {
            cout << " Ten  " << Name << endl;
        }
    private:
        string film;    
};

int main()
{
    people *Viet;
    wibu Huy{"Truong van Huy", 25, "onepiece"};
    Viet = &Huy;
    Viet->printAge();
    //Huy.printAge();
}