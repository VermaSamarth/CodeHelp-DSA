#include<iostream>
using namespace std;

#define PI 3.142

float areaCircle(float rad){
    return PI * rad * rad;
}

float perimeterCircle(float rad){
    return PI * 2 * rad;
}

int main(){
    cout << areaCircle(2.5) << endl;
    cout << perimeterCircle(2.5) << endl;

}