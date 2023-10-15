#include<iostream>
using namespace std;

int* solve(){
    int num=5;
    cout<<"Function Value: "<<num<<endl;
    cout<<"Function Address: "<<&num<<endl;
    int* ans=&num;
    return ans;
}
int main(){
    int a=5;
    cout<<&a<<endl;
    cout<<solve()<<endl;
}