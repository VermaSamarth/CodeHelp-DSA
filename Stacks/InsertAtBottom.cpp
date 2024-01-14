#include<iostream>
#include<stack>
using namespace std;

void InsertBottom(stack<int> &stk, int &num){
    if(stk.empty()){
        stk.push(num);
        return;
    }
    int temp = stk.top();
    stk.pop();
    InsertBottom(stk,num);
    stk.push(temp);
}

void print(stack<int> &stk){
    while(!stk.empty()){
        cout << stk.top() << " ";
        stk.pop();
    }
    cout << endl;
    return;
}

int main(){
    stack<int> stk;
    stk.push(10);
    stk.push(20);
    stk.push(30);
    stk.push(40);
    stk.push(50);
    stk.push(60);
    stk.push(100);
    
    int num = stk.top();
    stk.pop();
    InsertBottom(stk,num);
    cout << "After bottom insertion: " << endl;
    print(stk);
    
    return 0;
}