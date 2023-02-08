#include<iostream>
using namespace std;

//Explaining the value of PASS BY VALUE.
//In PASS BY VALUE, a copy is created and the actual value is not passed.
//Two different variables of same name can be used provided they are being used in the different functions.
//Those two variables will have the same number but the memory location?address will be different.


//Function to find the sum of two numbers.
int PrintSum(int num1, int num2)
{
    cout<<"Sum of the two numbers has been generated."<<endl<<endl;
    int sum=num1+num2;

    //Explaining the concept of Pass By Value, by updating the value of num1 and num2 in PrintSum function. 
    //This won't be reverted back to the main function.

    cout<<"Current value of num1 from the PrintSum function: "<<num1<<endl;
    num1++;

    cout<<"Current value of num2 from the PrintSum function: "<<num2<<endl<<endl;
    num2++;

    cout<<"Updated value of num1 from the PrintSum function: "<<num1<<endl;
    cout<<"updated value of num2 from the PrintSum function: "<<num2<<endl<<endl;

    //Returning the sum opf two numbers that we have generated.
    return sum;
}

int main()
{
    int num1, num2,sum=0;
    
    //Inputting the two numbering.
    cout<<"Enter the two numbers: "<<endl;
    cin>>num1>>num2;

    //Printing the current values of num1 and num2.
    cout<<"Current value of num1 from the main function: "<<num1<<endl;
    cout<<"Current value of num2 from the main function: "<<num2<<endl<<endl;

    //Printing the sum.
    sum=PrintSum(num1,num2);
    cout<<"Sum of the inputted numbers is: "<<sum<<endl;
    cout<<"Sum has been printed."<<endl<<endl;

    //Showing that changes made in the num1 and num2 in PrintSum are not reverted back to the main function. 
    cout<<"Value of num1 from the main function after execution of PrintSum function: "<<num1<<endl;
    cout<<"Value of num2 from the main function after execution of PrintSum function: "<<num2<<endl;
    return 0;
}