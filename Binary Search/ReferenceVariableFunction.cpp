#include<iostream>
using namespace std;
void update(int value){
    value++;
}
void solve(int& value){
    value++;
}
int main(){
    int a = 5;
    cout<<"a = "<<a<<endl;
    update(a);
    cout<<"Update a = "<<a<<endl;
    solve(a);
    cout<<"Solve a = "<<a<<endl;
}