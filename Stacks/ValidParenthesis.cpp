#include<iostream>
#include<stack>
using namespace std;

bool ValidParen(string &str){
    stack<char> stk;
    for(int i = 0; i < str.length(); i++){
        if(str[i] == '[' || str[i] == '(' || str[i] == '{'){
            stk.push(str[i]);
        }
        else{
            if(!stk.empty()){
                if(str[i] == '}' && stk.top() == '{')
                    stk.pop();
                else if(str[i] == ']' && stk.top() == '[')
                    stk.pop();
                else if(str[i] == ')' && stk.top() == '(')
                    stk.pop();
                else
                    return false;
            }
            else{
                return false;
            }
        }
    }
    if(stk.empty())
        return true;
    return false;
}

int main(){
    string str = "}{";
    bool ans = ValidParen(str);
    if(ans == true)
        cout << "Valid Parenthesis..." << endl;
    else
        cout << "Invalid Parenthesis..." << endl;
}