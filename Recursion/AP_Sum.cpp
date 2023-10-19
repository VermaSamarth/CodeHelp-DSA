// Sum of an Arthimetic Progression
// 0, 5, 10, 15, 20, -------- nth term
#include<iostream>
using namespace std;

void findSum(int n, int& sum){
    if(n == 0)
        return;
    sum+=n*5;
    return findSum(n-1,sum);
}

int main(){
    int n, sum = 0;
    cout << "Enter the value of n: " << endl;
    cin >> n;
    findSum(n,sum);
    cout << "Sum: " << sum << endl;
}