#include<iostream>
using namespace std;

 //Function to convert temperature from celsius to fahrenheit.
 void CelToFah(float cel)
 {
    cout<<"Temperature in Fahrenheit: "<<(9.0/5.0)*cel+32<<" F"<<endl;
 }

 //Function to convert temperature from fahreheit to celsius.
 void FahToCel(float fah)
 {
    cout<<"Temperature in Celsius: "<<(5.0/9.0)*(fah-32)<<" C"<<endl;
 }

//Main function
 int main()
 {
    char ch;
    float temp;

    //Enter the case for Switch case.
    cout<<"Enter the choice."<<endl;
    cout<<"Enter 'C' to convert from Celsius to Fahrenheit."<<endl<<"Enter 'F' to convert from Fahrenheit to Celcius."<<endl;
    cin>>ch;
    switch (ch)
    {
        //Case for converting temperature from celsius to fahreheit.
        case 'C':
        {
            cout<<"Enter the temperature in celsius: "<<endl;
            cin>>temp;
            CelToFah(temp);
            break;
        }

        //Case for converting temperature from fahrenheit to celsius.
        case 'F':
        {
            cout<<"Enter the temperature in fahrenheit: "<<endl;
            cin>>temp;
            FahToCel(temp);
            break;   
        }
        default:
        {
            cout<<"Invalid input."<<endl;
            break;
        }
    }
 }