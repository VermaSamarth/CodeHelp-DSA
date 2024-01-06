#include<iostream>
using namespace std;

class Animal{
    public:
        Animal(){
            cout << "I am inside Animal class...." << endl;
        }

        void speak(){
            cout << "Speaking...." << endl;
        }
};

class Dog: public Animal{
    public:
        Dog(){
            cout << "I am inside Dog class...." << endl;
        }

        void speak(){
            cout << "Barking...." << endl;
        }
};

int main(){
    // Animal* a = new Animal;

    // Animal* a = new Dog;

    Dog* a = new Dog;

    // Dog* a = (Dog*) new Animal;
}