#include<iostream>
#include<stack>
using namespace std;

int main(){
    stack<int> stk;

    // Insertion in the stack
    stk.push(10);
    stk.push(20);
    stk.push(30);
    stk.push(40);
    stk.push(50);
    stk.push(60);

    cout << "Size of stack before deletion: " << stk.size() << endl;
    cout << "Top of the stack rn is: " << stk.top() << endl << endl;

    // Deletion in the stack
    stk.pop();
    stk.pop();

    cout << "Size of stack after deletion: " << stk.size() << endl;
    cout << "Top of the stack rn is: " << stk.top() << endl;


    // Checking if the stack is empty or not
    if(stk.empty())
        cout << "Stack is empty..." << endl;
    else    
        cout << "Stack is not empty..." << endl;
    
    // Printing the stack
    cout << "Printing the stack: " ;
    while(!stk.empty()){
        cout << stk.top() << " ";
        stk.pop();
    }
    cout << endl;


    return 0;
} 