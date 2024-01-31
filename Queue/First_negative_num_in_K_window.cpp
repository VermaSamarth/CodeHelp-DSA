#include <iostream>
#include <deque>
#include <queue>
#include <vector>
using namespace std;

void firstNegativeInteger(vector<int> &arr, int k){
    if(k > arr.size()){
        cout << "Window size greater than vector size." << endl;
        return;
    }
    queue<int> que;

    // Index of negative integers of first window pushed in the queue
    for(int i = 0; i < k; i++){
        if(arr[i] < 0)
            que.push(i);
    }

    for(int i = k; i < arr.size(); i++){
        if(que.empty()){
            cout << 0 << " ";
        }
        else{
            cout << arr[que.front()] << " ";
        }

        if((!que.empty()) && ((i - que.front()) >= k)){
            que.pop();
        }

        if(arr[i] < 0)
            que.push(i);
    }

    if(que.empty()){
        cout << 0 << " ";
    }

}
int main(){
    vector<int> arr = {12,-1,-7,8,-15,30,16,28};
    int k = 3;
    firstNegativeInteger(arr,k);
}