#include<iostream>
#include<string>
#include<math.h>
using namespace std;

void Encryption(char arr[][100],int rows, int columns){
    
    string encryptedMessageText="";
    int i,j;
    for(i=0;i<columns;i++){
        for(j=0;j<rows;j++){
            if(arr[j][i]!='_')
            encryptedMessageText+=arr[j][i];
        }
    }
    cout<<"Encrypted String: "<<encryptedMessageText<<endl;
}

void Decryption(char arr[][100],int rows, int columns){
    string decryptedMessageText="";
    int i,j;
    for(i=0;i<rows;i++){
        for(j=0;j<columns;j++){
            if(arr[i][j]!='_')
            decryptedMessageText+=arr[i][j];
        }
    }
    cout<<"Decrypted String: "<<decryptedMessageText<<endl;
}

int main(void){
    
    string message,decryptedMessage="";
    int len,i,j,rows=4,columns,count=0;
    cout<<"Enter the string to be encrypted: "<<endl;
    getline(cin,message);

    len = message.length();   
    columns = ceil(len/(float)rows);
    char arr[rows][100];

    for(i=0;i<rows;i++){
        for(j=0;j<columns;j++){
            if(count<len){
                arr[i][j]=message[count];
                count++;
            }
            else{
                arr[i][j]='_';
            }
        } 
    }
    Encryption(arr,rows,columns);
    Decryption(arr,rows,columns);
    return 0;
}