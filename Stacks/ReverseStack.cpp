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

void ReverseStack(stack<int> &stk){
    if(stk.empty())
        return;
    int temp = stk.top();
    stk.pop();
    ReverseStack(stk);
    InsertBottom(stk,temp);
}

void print(stack<int> &stk){
    cout << "Printing the stack: " << endl;
    while(!stk.empty()){
        cout << stk.top() << " ";
        stk.pop();
    }
    cout << endl;
}

int main(){
    stack<int> stk;
    
    stk.push(10);
    stk.push(20);
    stk.push(30);
    stk.push(40);
    stk.push(50);
    stk.push(60);
    stk.push(70);

    ReverseStack(stk);
    print(stk);
}