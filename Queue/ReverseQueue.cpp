#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void ReverseQueue(queue<int> &que){
    if(que.empty())
        return;
    
    int num = que.front();
    que.pop();
    ReverseQueue(que);
    que.push(num);
    return;
}

void ReverseQueueUsingStack(queue<int> &que){
    stack<int> stk;
    while(!que.empty()){
        int num = que.front();
        que.pop();
        stk.push(num);
    }
    while(!stk.empty()){
        int num = stk.top();
        stk.pop();
        que.push(num);
    }
    return;
}

void printQueue(queue<int> &que){
    while(!que.empty()){
        cout << que.front() << " ";
        que.pop();
    }
    cout << endl;
    return;
}

int main(){
    queue<int> que;
    que.push(3);
    que.push(6);
    que.push(9);
    que.push(2);
    que.push(8);

    ReverseQueue(que);
    // ReverseQueueUsingStack(que);
    cout << "Printing the reverse Queue: ";
    printQueue(que);

}