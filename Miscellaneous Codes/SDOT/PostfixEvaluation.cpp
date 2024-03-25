#include<iostream>
#include<stack>
#include<algorithm>
#include<string>
using namespace std;

int postfixEvaluation(string str){
    stack<int> stk;
    for(auto it:str){
        if(isdigit(it)){
            stk.push(it - '0');
        }
        else{
            if(it == '/'){
                int num1 = stk.top();
                stk.pop();
                int num2 = stk.top();
                stk.pop();
                num1 = num2 / num1;
                stk.push(num1);
            }
            else if(it  == '*'){
                int num1 = stk.top();
                stk.pop();
                int num2 = stk.top();
                stk.pop();
                num1 = num2 * num1;
                stk.push(num1);
            }
            else if(it == '+'){
                int num1 = stk.top();
                stk.pop();
                int num2 = stk.top();
                stk.pop();
                num1 = num2 + num1;
                stk.push(num1);
            }
            else{
                int num1 = stk.top();
                stk.pop();
                int num2 = stk.top();
                stk.pop();
                num1 = num2 - num1;
                stk.push(num1);
            }
        }
    }
    return stk.top();
}

int main(){
    int num;
    string str;
    cin >> num;
    for(int i = 0; i < num; i++){
        cin >> str;
        cout << postfixEvaluation(str) << endl;
    }
}