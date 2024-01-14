#include<iostream>
using namespace std;

class Stack{
    public:
        int* arr;
        int top;
        int size;

        Stack(int size){
            arr = new int[size];
            this->size = size;
            this->top = -1;
        }

        void push(int data){
            // If the stack is full
            if(size - top > 1){
                ++top;
                arr[top] = data;
            }
            else{
                cout << "Stack Overflow." << endl;
            }
        }

        void pop(){
            if(top == -1){
                cout << "Stack Underflow." << endl;
            }
            else{
                top--;
            }
        }

        int getTop(){
            if(top == -1){
                cout << "Stack Underflow. There is no element in stack." << endl;
                return -1;
            }
            else{
                return arr[top];
            }
        }

        int stackSize(){
            return top + 1;
        }

        bool isEmpty(){
            if(top == -1)
                return true;
            else
                return false;
        }
};

int main(){
    Stack stk(5);

    stk.push(10);
    stk.push(20);
    stk.push(30);
    stk.push(40);
    stk.push(50);
    stk.push(60);
    
    while(!stk.isEmpty()){
        cout << stk.getTop() << " ";
        stk.pop();
    }
    cout << endl;

    cout << "Size of stack: " << stk.stackSize() << endl;
    return 0;   
}