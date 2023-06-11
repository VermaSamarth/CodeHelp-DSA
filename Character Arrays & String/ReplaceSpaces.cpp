#include<iostream>
#include<string.h>
using namespace std;

void ReplacedString(char arr[100], int length){
    for(int i=0; i<length; i++){
        if(arr[i]==' '){
            arr[i]='@';
        }
    }
    cout<<"After replacing spaces: "<<arr<<endl;
}

int main(){
    char arr[100];
    cout<<"Enter the string: "<<endl;
    cin.getline(arr,100);
    int length=0;
    while(arr[length]!='\0'){
        length++;
    }
    cout<<"Initially: "<<arr<<endl;
    ReplacedString(arr,length);
    return 0;
}