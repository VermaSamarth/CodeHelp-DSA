#include<iostream>
#include "bird.h"
using namespace std;

void BirdDoesSomething(Bird *&bird){
    bird->eat();
    bird->fly();
    bird->eat();
    bird->fly();
    bird->eat();
    bird->fly();
    bird->eat();
    bird->fly();
    bird->eat();
    bird->fly();
    bird->eat();
    bird->fly();
}

int main(){
    Bird *bird = new Sparrow();
    BirdDoesSomething(bird);

    Bird *birds = new Eagle();
    BirdDoesSomething(birds);

    // Just by chnaging the object in the line 21 and 24, we are able to chnage the characteristics of the bird.
}