//Encryption of the number key using the Bitwise Operators
#include<iostream>
using namespace std;

void ArithmeticOperations(int num1, int num2){
    cout<<"Addition Operation -> "<<num1<<"+"<<num2<<" = "<<(num1+num2)<<endl;
    cout<<"Subtraction Operation -> "<<num1<<"-"<<num2<<" = "<<(num1-num2)<<endl;
    cout<<"Multiplication Operation -> "<<num1<<"*"<<num2<<" = "<<(num1*num2)<<endl;
    cout<<"Division Operation -> "<<num1<<"/"<<num2<<" = "<<((float)num1/num2)<<endl;
}


int main(void){
    int num,key,encryptedNum;
    char chr;
    cout<<"Enter the numbers to be encrypted: "<<endl;
    cin>>num;
    cout<<"Enter the encryption key: "<<endl;
    cin>>key;
    cout<<"Enter the type of Encryption: "<<endl;
    cin>>chr;
    for(int i=num;i!=0;i/=10){
        int d = i%10;
        switch (chr)
        {
        case '&':
            cout<<"Num: "<<d<<" Key: "<<key<<" Encryption: "<<(d&key)<<endl;
            encryptedNum = encryptedNum*10 + (d&key);
            break;

        case '|':
            cout<<"Num: "<<d<<" Key: "<<key<<" Encryption: "<<(d|key)<<endl;
            encryptedNum = encryptedNum*10 + (d|key);
            break;

        case '~':
            cout<<"Num: "<<d<<" Key: "<<key<<" Encryption: "<<(~d)<<endl;
            encryptedNum = encryptedNum*10 + (~d);
            break;

        case '^':
            cout<<"Num: "<<d<<" Key: "<<key<<" Encryption: "<<(d^key)<<endl;
            encryptedNum = encryptedNum*10 + (d^key);
            break;

        case '<':
            cout<<"Num: "<<d<<" Key: "<<key<<" Encryption: "<<(d<<key)<<endl;
            encryptedNum = encryptedNum*10 + (d<<key);
            break;

        case '>':
            cout<<"Num: "<<d<<" Key: "<<key<<" Encryption: "<<(d>>key)<<endl;
        encryptedNum = encryptedNum*10 + (d>>key);
            break;

        default:
            break;
        }
    }
    cout<<"Encrypted Number: "<<encryptedNum<<endl<<endl;

    ArithmeticOperations(num,key);
    return 0;
}