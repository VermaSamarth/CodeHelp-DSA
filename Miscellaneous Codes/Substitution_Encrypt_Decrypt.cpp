#include<iostream>
#include<string>
using namespace std;

string Encryption(string data, int key){
    string encrypted="";
    char chr;
    for(int i=0; i<data.length();i++){
        chr = data[i]+key;
        encrypted=encrypted+chr;
    }
    return encrypted;
}

string Decryption(string data, int key){
    string decrypted="";
    for(int i=0; i<data.length();i++){
        char chr = data[i] - key;
        decrypted=decrypted+chr;
    }
    return decrypted;
}

int main(){
    string data,encryptData,decryptData;
    int key;
    cout<<"Enter the message to be sent: ";
    getline(cin,data);
    cout<<"Enter the key for encryption: ";
    cin>>key;
    cout<<"---------------------------------"<<endl;
    encryptData = Encryption(data,key);
    decryptData = Decryption(encryptData,key);
    cout<<"Inputted Data: "<<data<<endl;
    cout<<"Encrypted Data: "<<encryptData<<endl;
    cout<<"Decrypted Data: "<<decryptData<<endl;
}