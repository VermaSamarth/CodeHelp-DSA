#include<iostream>
using namespace std;

//Function to convert km into miles. Its return type is float.
float KmToMiles(float km)
{
    return (km*0.621371);
}

//This is the main function.
int main()
{
    float km;
    cout<<"Enter the distance in kilometers: "<<endl;
    cin>>km;
    cout<<"Distance in miles : "<<KmToMiles(km)<<endl;
    return 0;
}