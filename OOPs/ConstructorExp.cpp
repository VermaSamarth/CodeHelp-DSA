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

        // Constructor Creation
        Animal(){ //Default Constructor
            this->age = 0;
            this->name = "";
            cout << "Overidden default Constructor is called." << endl;
        }


        // Parameterised COnstructor
        Animal(int age, string name){
            this->age = age;
            this->name = name;
            cout << "Parameterised Constructor is called." << endl;
        }

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

        ~Animal(){
            cout << "Destructor Called." <<endl;
        }
};  

int main(){
    Animal* suresh = new Animal;
    suresh->age = 50;
    suresh->name = "Kutta";
    suresh->eat();
    suresh->sleep();

    Animal* mahesh = new Animal(45,"Mahesh");
    mahesh->age = 40;
    delete mahesh;

    Animal a;
    a.age = 12;

}