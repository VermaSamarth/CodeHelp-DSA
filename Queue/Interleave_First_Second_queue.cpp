#include <iostream>
#include <queue>
using namespace std;

void InterleaveTwoQueue(queue<int> &que){
    int len = que.size();
    int count = 0;
    queue<int> first;

    // Method 1:

    // while(!que.empty() && count <= len/2){
    //     first.push(que.front());
    //     que.pop();
    //     count++;
    // }
    // while(count <= len){
    //     if(!first.empty()){
    //         que.push(first.front());
    //         first.pop();
    //     }
    //     if(!que.empty()){
    //         que.push(que.front());
    //         que.pop();
    //     }
    //     count++;
    // }
    // return;


    // Method 2:
    while(!que.empty()){
        first.push(que.front());
        que.pop();
        count++;
        if(count == len/2)
            break;
    }
    while(!que.empty() && !first.empty()){
        que.push(first.front());
        first.pop();
        que.push(que.front());
        que.pop();
    }
    if(len & 1){
        que.push(que.front());
        que.pop();
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
    // que.push(10);
    // que.push(20);
    // que.push(30);
    // que.push(40);
    // que.push(50);
    // que.push(60);
    // que.push(70);
    // que.push(80);
    // que.push(90);
    InterleaveTwoQueue(que);
    cout << "Printing the queue after interleaving: ";
    printQueue(que);
}