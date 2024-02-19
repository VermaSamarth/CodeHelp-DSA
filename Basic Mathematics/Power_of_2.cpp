#include<iostream>
using namespace std;

int main(){
    int n = 512;
    if(n == 0){
        cout << "False" << endl;
        return 0;
    }
    while(n % 2 == 0)
        n = n / 2;
    if(n == 1){
        cout << "True" << endl;
        return 0;
    }
    cout << "False " << endl;
}