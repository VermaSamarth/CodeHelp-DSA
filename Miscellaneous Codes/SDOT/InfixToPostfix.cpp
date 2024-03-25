#include<iostream>
#include<stack>
#include<unordered_map>
using namespace std;

int main(){
    unordered_map<char,int> precedence;
    precedence['^'] = 3;
    precedence['*'] = 2;
    precedence['/'] = 2;
    precedence['+'] = 1;
    precedence['-'] = 1;

    string str, postfix = "";
    cin >> str;
    stack<char> stk;
    for(int i = 0; i < str.length(); i++){
        char chr = str[i];
        if(isalpha(chr)){
            postfix.push_back(chr);
        }
        else{
            if(chr == '(')
                stk.push(chr);
            else if(chr == ')'){
                while(!stk.empty() && stk.top() != '('){
                    postfix.push_back(stk.top());
                    stk.pop();
                }
                stk.pop();
            }
            else{
                if(!stk.empty() && precedence.find(chr) != precedence.end()){
                    while(!stk.empty() && precedence[chr] <= precedence[stk.top()]){
                        char ch = stk.top();
                        postfix.push_back(ch);
                        stk.pop();
                    }
                }
                stk.push(chr);
            }
        }
    }
    while(!stk.empty()){
        postfix = postfix + "" + stk.top();
        stk.pop();
    }
    cout << postfix << endl;
}