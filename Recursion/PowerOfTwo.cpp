#include<iostream>
using namespace std;

int findExpo(int num){
    if(num==1) return 2;
    int ans = 2 * findExpo(num-1);
    return ans;
}

int main(){
    int num;
    cout << "Enter the power value: " << endl;
    cin >> num;
    cout << "2 ^ "<< num << " = " << findExpo(num) << endl;
}