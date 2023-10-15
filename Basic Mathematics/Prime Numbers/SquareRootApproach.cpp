#include<iostream>
#include<math.h>
using namespace std;

int isPrime(int num){
    for(int i=2;i<=sqrt(num);i++){
        if(num%i==0)
            return 0;
    }
    return 1;
}

int main(){
    int n;
    cout<<"Enter the number: "<<endl;
    cin>>n;
    int count=0;
    for(int i=2;i<n;i++){
        if(isPrime(i)==1)
            count++;
    }
    cout<<"Number of Primes: "<<count<<endl;
}
