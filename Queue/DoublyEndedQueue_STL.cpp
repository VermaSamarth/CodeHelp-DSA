#include<iostream>
#include<deque>
using namespace std;

int main(){
    deque<int> deq;
    deq.push_back(10);
    deq.push_back(20);
    deq.push_back(30);
    deq.push_back(40);
    deq.push_front(50);
    deq.push_front(60);
    deq.push_front(70);

    cout << "Size of Queue: " << deq.size() << endl;
    cout << "Front: " << deq.front() << endl;
    cout << "Rear: " << deq.back() << endl;
    deq.pop_back();
    deq.pop_front();
    cout << "Size of Queue: " << deq.size() << endl;
    cout << "Front: " << deq.front() << endl;
    cout << "Rear: " << deq.back() << endl;
    
    if(deq.empty())
        cout << "Queue is empty." << endl;
    else    
        cout << "Queue is not empty." << endl;
}