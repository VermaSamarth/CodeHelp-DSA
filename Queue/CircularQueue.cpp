#include<iostream>
using namespace std;

class CircularQueue{
    public:
        int *arr;
        int size; 
        int front;
        int rear;
    
        CircularQueue(int size){
            this->size = size;
            arr = new int[size];
            this->front = -1;
            this->rear = -1;
        }

        void push(int data){
            // Queue is full
            if((front == 0 && rear == size - 1) || (front - rear == 1)){
                cout << "Queue is full. Cannot insert the items." << endl;
                return;
            }
            // First Element ka case
            else if(front == -1 && rear == -1){
                front = 0;
                rear = 0;
                arr[rear] = data;
            }
            // Cicular Nature
            else if(rear == size - 1 && front != 0){
                rear = 0;
                arr[rear] = data;  
            }
            // Default case
            else{
                rear++;
                arr[rear] = data;
            }
        }

        void pop(){
            // Empty case
            if(front == -1 && rear == -1){
                cout << "Queue is empty. Cannot remove the item." << endl;
            }
            // Single element in queue
            else if(front == rear){
                arr[front] = -1;
                front = -1;
                rear = -1;
            }
            // Circular nature
            else if(front == size - 1){
                arr[front] = -1;
                front = 0;
            }
            // Normal case
            else{
                arr[front] = -1;
                front++;
            }
        }

        int getFront(){
            if(front == -1 && rear == -1){
                cout << "Queue is empty." << endl;
            }
            return arr[front];
        }

        int getSize(){
            if(front == rear)
                return 1;
            if(rear > front){
                return rear - front;
            }
            else{
                return front - rear;
            }
        }

        void isEmpty(){
            if(front == -1 && rear == -1)
                cout << "Queue is empty." << endl;
            else
                cout << "Queue is not empty." << endl;
        }

};

int main(){
    CircularQueue que(6);

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
    que.push(70);
    cout << "Front of the queue after poping:" << que.getFront() << endl;
    cout << "Size of the queue: " << que.getSize() << endl << endl;
    que.pop();
    que.pop();
    que.pop();
    que.pop();
    cout << "Size of the queue: " << que.getSize() << endl;
    cout << "Front of the queue after poping:" << que.getFront() << endl;

    que.isEmpty();
}