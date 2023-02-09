#include<iostream>
using namespace std;


int PrintSetBits(int dec)
{
    //Creating a array of size 64 because it is the maximum number of bits that an system can support.
    long bin[64];
    int i=0,count=0;
    
    //Finding the binary equivalent of the inputted decimal number.
    while(dec>0)
    {
        bin[i++]=dec%2;
        dec/=2;

        //Counting the number of set bits in the binary number.
        if(bin[i-1]==1)
            count++;
    }

    //Printing the binary number produced.
    cout<<"Binary Equivalent of the number: ";
    for(int j=i-1;j>=0;j--)
    {
        cout<<bin[j];
    }

    cout<<endl<<"Number of Set Bits: ";

    //Returning the number of set bits calculated.
    return count;
}

int main()
{
    long dec;
    //Inputting the decimal value.
    cout<<"Enter the decimal: "<<endl;
    cin>>dec;

    //Function call PrintSetBits
    cout<<PrintSetBits(dec)<<endl;
    return 0;
}
