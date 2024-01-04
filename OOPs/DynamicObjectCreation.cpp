#include<iostream>
using namespace std;


// Creating a class  
class Animal{
    private:
    int weight;

    // Defined the scope of accessibility of the members of the class
    public: 
        // State or Properties
        int age;
        string name;

        // Behaviour
        void eat(){
            cout << name <<" is eating" << endl;
        }

        void sleep(){
            cout << name << " is sleeping" << endl;
        }

        // Setters Function
        void setWeight(int weight){
            this->weight = weight;
        }

        // Getters Function
        int getWeight(){
            return weight;
        }
};  

int main(){
    // cout << "Size of Class Animal: " << sizeof(AnimalCat) << endl;
    // cout << "Hello World" << endl;

    // Creating an Object for the class
    // Static Memory
    // Animal Ramesh;
    // cout << "Name of Ramesh is " << Ramesh.name << endl;
    // cout << "Age of Ramesh is " << Ramesh.age << endl;

    // // Access or Update the properties of the Class
    // Ramesh.age = 20;
    // Ramesh.name = "Dog";
    // cout << "Name of Ramesh is " << Ramesh.name << endl;
    // cout << "Age of Ramesh is " << Ramesh.age << endl;

    // Ramesh.eat();
    // Ramesh.sleep();

    // // Calling private member of the class using getter and setter
    // Ramesh.setWeight(100);
    // cout << "Weight of Ramesh is " << Ramesh.getWeight() << endl;


    // Dynamic Memory
    Animal* suresh = new Animal;
    (*suresh).age = 40;
    (*suresh).name = "Billi";
    (*suresh).eat();
    (*suresh).sleep();

    // Alternative way
    suresh->age = 50;
    suresh->name = "Kutta";
    suresh->eat();
    suresh->sleep();
}