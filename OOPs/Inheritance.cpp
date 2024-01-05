#include<iostream>
using namespace std;


class Animal{
    public:
        int age;
        int weight;

        void eat(){
            cout << "Eating!!!" << endl;
        }
};

class Dog: public Animal{

};
// Animal to Dog is a single level inheritance


class Cat: protected Animal{
    public: 
        void print(){
            cout << this->age << endl;
        }
};

class Mouse: private Animal{
    public:
        void print(){
            cout << this->age << endl;
        }
};

// Animal to Dog, Cat and Mouse is an example of Hiearchical Inheritance

int main(){
    Dog* newDog = new Dog;
    newDog->eat();
    cout << newDog->age << endl;

    Cat c1;
    c1.print();

    Mouse m1;
    m1.print();
}