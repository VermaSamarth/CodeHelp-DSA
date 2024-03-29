#include<iostream>
using namespace std;

class AnimalCat{
    // Empty Class
    // System allots the minimum required space i.e. 1, through which the existence of the class can be defined.
    // It doesn't allot it to 0 because



    // Non-Empty Class
    int age;
    int weight;
    char chr;  
};

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
            cout << "Eating" << endl;
        }

        void sleep(){
            cout << "Sleeping" << endl;
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
    Animal Ramesh;
    cout << "Name of Ramesh is " << Ramesh.name << endl;
    cout << "Age of Ramesh is " << Ramesh.age << endl;

    // Access or Update the properties of the Class
    Ramesh.age = 20;
    Ramesh.name = "Dog";
    cout << "Name of Ramesh is " << Ramesh.name << endl;
    cout << "Age of Ramesh is " << Ramesh.age << endl;

    Ramesh.eat();
    Ramesh.sleep();

    // Calling private member of the class using getter and setter
    Ramesh.setWeight(100);
    cout << "Weight of Ramesh is " << Ramesh.getWeight() << endl;
    // Dynamic Memory
}