#include<iostream>
#include<string.h>
using namespace std;

int main(){
    char name[100];
    cout<<"Enter the name: "<<endl;
    cin>>name;
    
    int length=0;
    while(name[length]!='\0'){
        length++;
    }
    cout<<"Aapka naam hain: "<<name<<endl;
    cout<<"Aapke naam ki length hai: "<<length<<endl;

    cout<<"Predefined function se aapke naam ki length: "<<strlen(name)<<endl;
    return 0;
}