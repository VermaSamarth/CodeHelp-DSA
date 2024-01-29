#include<iostream>
#include<vector>
using namespace std;

class MyQueue {
public:
    vector<int> arr;
    int front;
    int rear;
    MyQueue() {
        front = 0;
        rear = 0;
    }
    
    void push(int x) {
        arr.push_back(x);
        rear++;
        cout << "Pushed the value " << x << " into the queue." << endl;
    }
    
    void pop() {
        ++front;
        cout << "Value popped from the queue: " << arr[front-1] << endl;
    }
    
    void peek() {
        cout << "Value at the front of the queue: " << arr[front] << endl;
    }
    
    void empty() {
        if(front == rear)
            cout << "Queue is empty." << endl;
        else
            cout << "Queue is not empty." << endl;
    }
};

int main(){
    vector<string> operations = {"MyStack", "Push", "Push", "Peek", "Pop", "Empty"};
    int count = 0;
    vector<int> values = {1,2};
    MyQueue* obj = new MyQueue();
    for(int i = 0; i < operations.size(); i++){
        if(operations[i] == "Push"){
            obj->push(values[count]);
            count++;
        }
        else if(operations[i] == "Pop"){
            obj->pop();
        }
        else if(operations[i] == "Peek"){
            obj->peek();
        }
        else if(operations[i] == "Empty"){
            obj->empty();
        }
    }
}