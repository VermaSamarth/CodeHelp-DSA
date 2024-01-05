#include<iostream>
using namespace std;

// Encapsulation

class Animal{
    public:
        int age;
        int weight;

        void eat(){
            cout << "Eating!!!" << endl;
        }
};

// Perfect Encapsulation

class Humans{
    private:
        int age;
        int weight;
    
    public:
        void setAge(int age){
            this->age = age;
        }
        int getAge(){
            eat();
            cout << "Age is returned!!!" << endl;
            return this->age;
        }

    private:
        void eat(){
            cout << "Eating!!!!" << endl;
        }
};

int main(){
    Animal* newAnimal = new Animal;
    newAnimal->eat();

    Humans* newHuman = new Humans;
    newHuman->setAge(20);
    newHuman->getAge();
}