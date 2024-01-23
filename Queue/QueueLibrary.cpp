#include<iostream>
#include<queue>
using namespace std;

int main(){
    queue<int> que;

    que.push(10);
    que.push(20);
    que.push(30);
    que.push(40);
    que.push(50);
    que.push(60);

    cout << "Size of queue before poping: " << que.size() << endl;
    cout << "Front element: " << que.front() << endl;
    que.pop();
    cout << "Size of queue after poping: " << que.size() << endl;
    cout << "Front element: " << que.front() << endl;

    if(que.empty())
        cout << "Queue is empty..." << endl;
    else    
        cout << "Queue is not empty..." << endl;
}