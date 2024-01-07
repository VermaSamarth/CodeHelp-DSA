#include<iostream>
using namespace std;

class Animal{
    private:
        int age;
    public:
        Animal(int a): age(a){};

        void setAnimal(int age){
            this->age = age;
        } 
        int getAnimal(){
           return age; 
        }
    
    friend class Bird;
    friend void print(Animal &a);
};

class Bird{
    public:
    void print(Animal &a){
        cout << "Friend class: " << a.age << endl;
    }
};

void print(Animal &a){
    cout << "Friend Function: " << a.age << endl;
}

int main(){
    Animal an(20);
    Bird bd;
    bd.print(an);
    print(an);
}