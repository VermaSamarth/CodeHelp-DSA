#include<iostream>
using namespace std;

//Function to calculate the radius of the circle with FLOAT as its return type with INT as its input parameter.
float AreaCircle(int radius)
{
    //Returning the found area of the circle.
    return (radius*radius)*(22/7.0);
}

int main()
{
    int radius;
    //Inputting the radius of the circle.
    cout<<"Enter the radius of the cicle: "<<endl;
    cin>>radius;

    //Printing the radius of the circle.
    cout<<"Area of the circle of radius = "<<radius<<" is "<<AreaCircle(radius)<<endl;
    return 0;
}