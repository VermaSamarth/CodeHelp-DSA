#include<iostream>
using namespace std;

class Stack{
    public:
        int size;
        int* arr;
        int top1;
        int top2;

        Stack(int size){
            this->size = size;
            arr = new int[size];
            this->top1 = -1;
            this->top2 = size;
        }

        void push1(int data){
            if(top2 - top1 == 1){
                cout << "Stack Overflow. Can't push element into the stack." << endl;
                return;
            }
            top1++;
            arr[top1] = data;
            return;
        }

        void pop1(){
            if(top1 != -1){
                arr[top1] = 0;
                top1--;
                return;
            }
            cout << "Stack Underflow. Can't pop the element from the stack." << endl;
            return;
        }

        void push2(int data){
            if(top2 - top1 == 1){
                cout << "Stack Overflow. Can't push element into the stack." << endl;
                return;
            }
            --top2;
            arr[top2] = data;
            return;
        }

        void pop2(){
            if(top2 != size){
                arr[top2] = 0; 
                top2++;
                return;
            }
            cout << "Stack Underflow. Can't pop the element from the stack." << endl;
            return;
        }

        void printStack(){
            cout << "Top1: " << top1 << endl;
            cout << "Top2: " << top2 << endl;
            for(int i = 0; i < size; i++){
                cout << arr[i] << " ";
            }
            cout << endl;
        }
};

int main(){     
    Stack stk(10);

    stk.push1(10);
    stk.printStack();
    stk.push1(20);
    stk.printStack();
    stk.push1(30);
    stk.printStack();
    stk.push1(40);
    stk.printStack();
    stk.push1(50);
    stk.printStack();
    
    stk.push2(100);
    stk.printStack();
    stk.push2(90);
    stk.printStack();
    stk.push2(80);
    stk.printStack();
    stk.push2(70);
    stk.printStack();
    stk.push2(60);
    stk.printStack();
    stk.push2(1000);
    stk.printStack();
    stk.push1(2000);
    stk.printStack();

    stk.pop1();
    stk.printStack();
    stk.pop2();
    stk.printStack();
    stk.pop1();
    stk.printStack();
    stk.pop2();
    stk.printStack();
    
    stk.push2(1000);
    stk.printStack();
    stk.push1(2000);
    stk.printStack();
    return 0;
}
