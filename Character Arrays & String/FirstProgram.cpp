#include<iostream>
#include<string.h>
using namespace std;

int main(){
    char name[100];
    char arr[100];
    // cout<<"Enter your name: "<<endl;
    // cin>>name;
    // cout<<"Aapka naam hai: "<<name<<endl;
    
    cout<<"Enter the name: "<<endl;
    cin.getline(arr,50);
    cout<<"Aapka naam hain: "<<arr<<endl;
    return 0;
}