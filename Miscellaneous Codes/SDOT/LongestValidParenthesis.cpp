#include<iostream>
#include<stack>
using namespace std;

int main(){
    string str;
    cin >> str;
    int maxlen = 0;
    stack<int> stk;
    stk.push(-1);
    for(int i = 0; i < str.length(); i++){
        if(str[i] == '('){
            stk.push(i);
        }
        else{
            if(!stk.empty()){
                stk.pop();
            }
            if(!stk.empty()){
                maxlen = max(maxlen, i - stk.top());
            }
            else    
                stk.push(i);
        }
    }
    cout << maxlen << endl;
}