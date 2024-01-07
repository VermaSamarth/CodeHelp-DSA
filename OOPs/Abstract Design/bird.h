// Header file created to show abstraction

#if !defined(BIRD_H)
#define BIRD_H
#include<iostream>
using namespace std;

class Bird{
    public:
        virtual void eat() = 0;
        virtual void fly() = 0;  
        // Classes that inherits this class,
        // has to implement the above pure virtual function.
};

class Sparrow: public Bird{
    public:
        void eat(){
            cout << "Sparrow is eating..." << endl;
        }

        void fly(){
            cout << "Sparrow is flying..." << endl;
        }

};

class Eagle: public Bird{
    public:
        void eat(){
            cout << "Eagle is eating..." << endl;
        }

        void fly(){
            cout << "Eagle is flying..." << endl;
        }

};
#endif