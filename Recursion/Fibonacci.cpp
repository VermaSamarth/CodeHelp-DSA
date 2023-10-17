#include <iostream>
using namespace std;

int fibonacci(int num){
    // First Number will always be 0.
    if(num == 1) return 0;
    // Second number will always be 1.
    if(num == 2) return 1;
    int ans = fibonacci(num-1) + fibonacci(num-2);
    return ans;
}
int main(){
    int num;
    cout << "Enter the number you want to see: " << endl;
    cin >> num;
    int ans = fibonacci(num);
    cout << num <<"th fibonacci number: " << ans <<endl;
}