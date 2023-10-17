#include<iostream>
using namespace std;

int factorial(int number){
    if(number == 1)
        return 1;
    int smallerProblem = factorial(number-1);   
    int biggerProblem = number*smallerProblem;  // Similar to [f(n) = n * f(n-1)]
    return biggerProblem;
}

int main(){
    int num;
    cout<<"Enter the number: "<<endl;
    cin>>num;
    cout<<"Factorial of number "<<num<<" is "<<factorial(num)<<endl;
}