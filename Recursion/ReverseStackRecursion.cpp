#include<iostream>
#include<stack>
using namespace std;

void InsertBottomStack(stack<int>&stk, int&top){
    if(stk.empty()){
        stk.push(top);
        return;
    }
    int temp = stk.top();
    stk.pop();
    InsertBottomStack(stk,top);
    stk.push(temp);
    return;
}

void ReverseStack(stack<int>&stk){
    if(stk.empty())
        return;
    int top = stk.top();
    stk.pop();
    ReverseStack(stk);
    InsertBottomStack(stk,top);
}

int main(){
    stack<int> stk;
    stk.push(10);
    stk.push(20);
    stk.push(30);
    stk.push(40);
    stk.push(50);
    stk.push(60);

    ReverseStack(stk);
    cout << "Reverse Stack: " << endl;
    while(!stk.empty()){
        cout << stk.top() << " ";
        stk.pop();
    }
    cout << endl;
}