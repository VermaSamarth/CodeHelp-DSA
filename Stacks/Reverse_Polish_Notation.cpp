#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

int evalRPN(vector<string> &tokens){
    stack<int> stk;
    int num, num1, num2, ans;
    for (int i = 0; i < tokens.size(); i++){
        if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"){
            num1 = stk.top();
            stk.pop();
            num2 = stk.top();
            stk.pop();
            if (tokens[i] == "+"){
                ans = num1 + num2;
                stk.push(ans);
            }
            else if (tokens[i] == "-"){
                ans = num2 - num1;
                stk.push(ans);
            }
            else if (tokens[i] == "*"){
                ans = num1 * num2;
                stk.push(ans);
            }
            else if (tokens[i] == "/"){
                ans = num2 / num1;
                stk.push(ans);
            }
        }
        else{
            num = stoi(tokens[i]);
            stk.push(num);
        }
    }
    return stk.top();
}

int main()
{
    vector<string> tokens = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    int ans = evalRPN(tokens);
    cout << "Answer: " << ans << endl;
}