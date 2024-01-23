#include<iostream>
using namespace std;
class DoublyQueue{
    public:
        int *arr;
        int size;
        int front;
        int rear;

        DoublyQueue(int size){
            this->size = size;
            arr = new int[size];
            this->front = -1;
            this->rear = -1;
        }

        void pushRear(int data){
            // Queue is empty or not.
            if((front == 0 && rear == size - 1) || (front - rear == 1)){
                cout << "Queue is full. Cannot insert the items." << endl;
            }
            // First Element ka case
            else if(front == -1 && rear == -1){
                front = 0;
                rear = 0;
            }
            // Cicular Nature
            else if(rear == size - 1 && front != 0){
                rear = 0;
            }
            // Default case
            else{
                rear++;
            }
            arr[rear] = data;
        }

        void pushFront(int data){
             // Queue is empty or not.
            if((front == 0 && rear == size - 1) || (front - rear == 1)){
                cout << "Queue is full. Cannot insert the items." << endl;
            }
            // First Element ka case
            else if(front == -1 && rear == -1){
                front = 0;
                rear = 0;
            }
            // Cicular Nature
            else if(rear != size - 1 && front == 0){
                front = size - 1;
            }
            // Default case
            else{
                front--;
            }
            arr[front] = data;
        }

        void popFront(){
            if(front == -1 && rear == -1){
                cout << "Queue is empty. Cannot remove the item." << endl;
                return;
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

        void popRear(){
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
            else if(rear == 0){
                arr[front] = -1;
                rear = size - 1;
            }
            // Normal case
            else{
                arr[rear] = -1;
                rear--;
            }
        }

        void print(){
            cout << "Printing the Queue: " << endl;
            for(int i = 0; i < size; i++){
                cout << arr[i] << " ";
            }
            cout << endl;
        }
};

int main(){
    DoublyQueue dobque(6);
    dobque.pushFront(10);
    dobque.pushFront(20);
    dobque.pushFront(30);
    dobque.pushRear(40);
    dobque.pushRear(50);
    dobque.pushRear(60);
    dobque.print();

    dobque.popFront();
    dobque.popRear();
    dobque.print();

}