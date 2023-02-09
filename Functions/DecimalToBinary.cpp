#include<iostream>
using namespace std;

//Function to find the Binary equivalent of the inputted Decimal with return type as void.
//Using long data type so that we can store 64 bit values.
void DecToBin(long num)
{
    //Creating a array of size 64 because it is the maximum number of bits that an system can support.
    long bin[64];
    int i=0;
    
    //Finding the binary equivalent of the inputted decimal number.
    while(num>0)
    {
        bin[i++]=num%2;
        num/=2;
    }

    //Printing the binary number produced.
    for(int j=i-1;j>=0;j--)
    {
        cout<<bin[j];
    }
    
}

int main()
{
    long dec;
    //Inputting the decimal value.
    cout<<"Enter the decimal: "<<endl;
    cin>>dec;

    //Function call for DecToBin
    DecToBin(dec);
    return 0;
}
