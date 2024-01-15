#include<iostream>
#include<stack>
using namespace std;

int main(){
    string str = "((a+b)+d)";
    stack<char> stk;
    bool temp = false;
    for(int i = 0; i < str.length(); i++){
        if(str[i] == '(' || str[i] == '*' || str[i] == '+' || str[i] == '/' || str[i] == '-'){
            stk.push(str[i]);
        }
        else{
            if(str[i] == ')'){
                if(!stk.empty()){
                    if(stk.top() == '+' || stk.top() == '+' ||stk.top() == '+' || stk.top() == '+'){
                        temp = true;
                        stk.pop();
                        stk.pop();
                    }
                    else{
                        temp = false;
                        break;
                    }
                }
                else{
                    temp = false;
                    break;
                }
            }
        }
    }
    if(temp == false)
        cout << "Redundant brackets present." << endl;
    else
        cout << "Redundant brackets not present." << endl;
}