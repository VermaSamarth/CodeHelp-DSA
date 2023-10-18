#include<iostream>
#include<limits.h>
using namespace std;

void Maximum(int arr[], int num, int i, int& maxi){
    // int& -> Reference Variable
    // We need to pass maxi using pass by refernce. Here we are sending the maxi using pass by refence.
    // Base Condition
    
    if(i==num)
    // Array poora traverse hogya hai
        return;
    
    // Checking if the current larger than maxi.
    if(maxi<arr[i]){
        maxi = arr[i];
    }
    
    // Recursion function call
    Maximum(arr,num,++i,maxi);
}

void Minimum(int arr[], int size, int i, int& mini){
    if(i>=size)
        return;
    mini=min(mini,arr[i]);
    Minimum(arr,size,++i,mini);
}

int main(){
    int arr[6] = {12,43,10,54,22,31};
    int size = 6;
    int maxi = INT_MIN, mini = INT_MAX;
    int i = 0;
    Maximum(arr,size,i,maxi);
    cout << "Maximum in the array: " << maxi <<endl;
    Minimum(arr,size,i,mini);
    cout << "Minimum in the array: " << mini <<endl;
}