#include<iostream>
#include<stack>
using namespace std;

void findMiddle(stack<int> &stk, int &len){
    if(stk.size() == 0){
        cout << "Stack Underflow." << endl;
        return; 
    }
    
    // Base Case   
    if((len/2 + 1) == stk.size()){
        cout << "Middle element of the stack: " << stk.top() << endl;
        return;
    }
    int temp = stk.top();
    stk.pop();
    
    // Recursive call
    findMiddle(stk,len);
    
    // Backtracking
    stk.push(temp);
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
    stk.push(80);
    stk.push(80);

    int len = stk.size();
    findMiddle(stk,len);
}