#include<iostream>
using namespace std;

class Animal{
    public:

        // It is not declared as virtual therefore it will be executed for line 39.
        // void speak(){
        //     cout << "Speaking!!!" << endl;
        // }


        // If it is declared as virtual then in that case, child class ka speak function will be executed.
        virtual void speak(){
            cout << "Speaking!!!" << endl;
        }
};

class Dog: public Animal{
    public:
    // Function Overriding
        void speak(){
            cout << "Barking..." << endl;
        }
};

int main(){
    // Animal a;
    // Dog d;
    // a.speak();
    // d.speak();

//     Animal* a = new Animal;
//     a->speak();

//     Dog* d = new Dog;
//     d->speak();

    Animal* a = new Dog;    // UPCASTING
    a->speak();
    
    // Dog* d = new Animal;     --> Not Allowed : ERROR ---> DOWNCASTING
    Dog* d = (Dog*) new Animal; // Explicit Downcasting
    d->speak();
}