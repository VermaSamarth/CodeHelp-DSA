#include<iostream>
using namespace std;

int main(){
    int num;
    cin >> num;
    int fact = 1;
    for(int i = 2; i <= num; i++)
        fact = fact * i;
    while((fact % 10) == 0){
        fact = fact / 10;
    }
    cout << fact % 10 << endl;
}