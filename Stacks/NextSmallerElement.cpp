#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(){
    vector<int> arr;
    vector<int> ans;
    arr.push_back(2);
    arr.push_back(1);
    arr.push_back(4);
    arr.push_back(2);
    arr.push_back(5);
    arr.push_back(3);

    stack<int> stk;
    stk.push(-1);
    int index = arr.size() - 1;
    
    while(index != -1){
        if(stk.top() < arr[index]){
            ans.push_back(stk.top());
            stk.push(arr[index]);
        }
        else{
            while(stk.top() >= arr[index]){
                stk.pop();
            }
            ans.push_back(stk.top());
            stk.push(arr[index]);
        }  
        index--;
    }

    cout << "Printing the next smaller for each data: " << endl;
    for(int i = ans.size()-1; i != -1; i--){
        cout << ans[i] << " ";
    }
        cout << endl;
}