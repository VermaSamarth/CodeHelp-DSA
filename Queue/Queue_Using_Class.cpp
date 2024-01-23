#include<iostream>
using namespace std;

class Queue{
    public:
        int *arr;
        int size; 
        int front;
        int rear;
    
        Queue(int size){
            this->size = size;
            arr = new int[size];
            this->front = 0;
            this->rear = 0;
        }

        void push(int data){
            if(rear == size)
                cout << "Queue is full. Cannot insert the data..." << endl;
            else{
                arr[rear] = data;
                rear++;
            }
        }

        void pop(){
            if(front == rear)
                cout << "Queue is empty. Cannot remove the data..." << endl;
            else{
                arr[front] = -1;
                front++;
                if(front == rear){
                    front = 0;
                    rear = 0;
                }
            }
        }

        int getFront(){
            if(front == rear){
                cout << "Queue is empty. Cannot return the front..." << endl;
                return -1;
            }
            else 
                return arr[front];
        }
        
        int getSize(){
            return rear - front;
        }

        void isEmpty(){
            if(front == rear)
                cout << "Queue is empty..." << endl;
            else
                cout << "Queue is not empty...." << endl;
        }
};

int main(){
    Queue que(10);

    que.push(10);
    que.push(20);
    que.push(30);
    que.push(40);
    que.push(50);
    que.push(60);
    cout << "Size of the queue: " << que.getSize() << endl;
    cout << "Front of the queue:" << que.getFront() << endl << endl;
    que.pop();
    que.pop();
    cout << "Front of the queue after poping:" << que.getFront() << endl;
    cout << "Size of the queue: " << que.getSize() << endl << endl;
    que.pop();
    que.pop();
    que.pop();
    que.pop();
    cout << "Size of the queue: " << que.getSize() << endl;

    que.isEmpty();
}