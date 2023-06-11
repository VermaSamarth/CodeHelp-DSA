#include<iostream>
#include<string.h>
using namespace std;

void ReversedString(char arr[100], int length){
    cout<<"Initially String: "<<arr<<endl;
    int start = 0, end = length-1;
    while(start<=end){
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
    cout<<"Reversed String: "<<arr<<endl;   
}


int main(){
    char arr[100];
    cout<<"Enter the string: "<<endl;
    cin>>arr;
    int length=0;
    while(arr[length]!='\0'){
        length++;
    }
    ReversedString(arr,length);
    return 0;
}