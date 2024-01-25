#include<iostream>
#include<stack>
using namespace std;

int main(){
    string str = "";
    string ans = "";
    cout << "Enter the string: " << endl;
    cin >> str;
    stack<char> stk;
    for(int i = 0; i < str.length(); i++){
        stk.push(str[i]);
    }

    while(!stk.empty()){
        if(stk.top() == ')'){
            stk.pop();
            if(stk.top() == '('){
                stk.pop();
                ans = ans + "()";
            }
        }
        else{
            stk.pop();
        }
    }
    cout << "Answer: " << ans << endl;
}