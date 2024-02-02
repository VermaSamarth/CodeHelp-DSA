#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;

// Approach 1: Working but time limit exceeded

// bool checkSequential(int num){
//     stack<int> stk;
//     for(int i = num; i != 0; i/=10){
//         stk.push((i%10));
//     }
//     while(!stk.empty()){
//         int stktop = stk.top();
//         stk.pop();
//         if(stk.empty() == false && (stk.top() - 1) != stktop)  
//             return false;
//     }
//     return true;
// }
// int main(){
//     int start = 100, end = 13000;
//     vector<int> ans;
//     for(int i = start; i <= end; i++){
//         if(checkSequential(i))
//             ans.push_back(i);
//     }
//     cout << "Sequential Numbers: " ;
//     for(int i = 0; i < ans.size(); i++)
//         cout << ans[i] << " ";
//     cout << endl;
// }


// Approach 2: 

int main(){
    int start = 100, end = 13000;
    vector<int> ans;
    for(int i = 1; i <= 9; i++){
        int num = i;
        int nextNum = i + 1;

        while(num <= end && nextNum <= 9){
            num = (num * 10) + nextNum;
            if(num >= start && num <= end)
                ans.push_back(num);
            ++nextNum;
        }
        sort(ans.begin(), ans.end());
    }
    cout << "Sequential Numbers: " ;
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << endl;
}