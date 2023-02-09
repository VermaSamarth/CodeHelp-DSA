
#include<iostream>
using namespace std;

void PrintSetBits(int dec, int set)
{
    //Creating a array of size 64 because it is the maximum number of bits that an system can support.
    long bin[64];
    int i=0;
    
    //Finding the binary equivalent of the inputted decimal number.
    while(dec>0)
    {
        bin[i++]=dec%2;
        dec/=2;
    }

    //Printing the binary number produced.
    cout<<"Binary Equivalent of the number: ";
    for(int j=i-1;j>=0;j--)
    {
        cout<<bin[j];
    }
    
    //Checking if the bit to be manipulated is less than the length of the binary equivalent.
    if(set<i)
    {
        //If bit is 0, then change it to 1.
        if(bin[i-set]==0)
            bin[i-set]=1;

        //If bit is 1, then change it to 0.
        else
            bin[i-set]=0; 

        //Printing the binary number after setting the ith bit.
        cout<<endl<<"Binary Equivalent of the number after setting the ith bit: ";
        for(int j=i-1;j>=0;j--)
        {
            cout<<bin[j];
        }
    }

    //If ith bit > length then printing.....
    else
        cout<<endl<<"Length of bits is less the ith bit."<<endl; 
}



int main()
{
    long dec,i;
    //Inputting the decimal value.
    cout<<"Enter the decimal: "<<endl;
    cin>>dec;

    //inputting the ith element to be manipulated.
    cout<<"Enter the ith element to be setted: "<<endl;
    cin>>i;
    //Function call PrintSetBits
    PrintSetBits(dec,i);
    return 0;
}
