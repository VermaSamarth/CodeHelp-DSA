#include <iostream>
#include <stack>
#include <queue>
using namespace std;

void ReverseKQueue(queue<int> &que, int k){
    if(k < 0 || k >= que.size()){
        return;
    }
    int count = 0;
    int len = que.size();
    stack<int> stk;
    while(count < k){
        int num = que.front();
        que.pop();
        stk.push(num);
        count++;
    }
    
    while(!stk.empty()){
        int num = stk.top();
        stk.pop();
        que.push(num);
    }

    while(k < len){
        int num = que.front();
        que.pop();
        que.push(num);
        k++;
    }
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

    ReverseKQueue(que, 6);
    cout << "Queue after reversing the first K elements: ";
    printQueue(que);
}