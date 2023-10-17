#include<iostream>
using namespace std;

void printCounting(int number) {
    if(number == 1) {
        cout<<"1"<<endl;
        return;
    }
    cout<<number<<" ";
    printCounting(number-1);
}

int main(){
    int num;
    cout<<"Enter the number: "<<endl;
    cin>>num;
    cout<<"Counting of number: ";
    printCounting(num);
}