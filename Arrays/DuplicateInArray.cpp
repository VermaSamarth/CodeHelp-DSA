#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
    vector<int> arr = {4,3,2,7,8,2,3,1};
    queue<int> que;
    int it,num;
    for(int i = 0; i < arr.size(); i++){
        it = abs(arr[i]);
        num = arr[it - 1];
        if(arr[it - 1] < 0)
            que.push(abs(arr[it-1]));
        else
            arr[it - 1] = 0 - num;
    }
    arr.clear();
    while(!que.empty()){
        arr.push_back(que.front());
        que.pop();
    }
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << endl;
    }
}