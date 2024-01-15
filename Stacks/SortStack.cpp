#include<iostream>
#include<stack>
using namespace std;

void InsertSorted(stack<int> &stk, int &target){
    if(stk.empty()){
        stk.push(target);
        return;
    }

    if(stk.top() >= target){
        stk.push(target);
        return;
    }
    int topElement = stk.top();
    stk.pop();
    InsertSorted(stk,target);
    stk.push(topElement);
}

void SortedStack(stack<int> &stk){
    if(stk.empty()){
        return;
    }
    int temp = stk.top();
    stk.pop();
    SortedStack(stk);
    InsertSorted(stk,temp);
    return;
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

    stk.push(60);
    stk.push(80);
    stk.push(10);
    stk.push(50);
    stk.push(40);
    stk.push(70);
    stk.push(20);
    SortedStack(stk);
    print(stk);
}