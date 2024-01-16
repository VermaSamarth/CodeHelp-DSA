#include<iostream>
#include<stack>
using namespace std;

int main(){
    string str = ")))())()()";
    int maxLen = 0;
    stack<int> stk;
    stk.push(-1);
    if(str == "")
        cout << "Length of longest valid parenthesis is 0." << endl;
    
    for(int i = 0; i < str.length(); i++){
        char chr = str[i];
        if(str[i] == '(')
            stk.push(i);
        else{
            stk.pop();
            if(stk.empty()){
                stk.push(i);
            }
            else{
                int len = i - stk.top();
                maxLen = max(len,maxLen);
            }
        }
    }
    cout << "Length of longest valid parethesis is " << maxLen << "." << endl;
    return 0;
}