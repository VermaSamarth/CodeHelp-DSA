#include <iostream>
#include <stack>
using namespace std;
bool checkValidString(string s){
    // int count1 = 0, count2 = 0;
    // for (auto it : s){
    //     if (it == '('){
    //         stk.push('(');
    //         count1++;
    //     }   
    //     else if (it == ')'){
    //         count2++;
    //         if (!stk.empty() && stk.top() == '(')   stk.pop();
    //         else    stk.push(')');
    //     }
    //     else    ast.push('*');
    // }
    // cout << count1 << " " << count2 << " " << ast.size() << endl;
    // if (stk.empty())
    //     return true;
    // if (!ast.empty() && ast.size() >= stk.size()){
    //     return true;
    // }
    // return false;
    stack<char> stk;
    stack<char> ast;
    for(auto it : s){
        if(it == ')' && !stk.empty() && (stk.top() == '(' || stk.top() == '*'))
            stk.pop();
        else    
            stk.push(it);
    }
    if(stk.empty()) 
        return true;
    return false;
    
}
int main()
{
    string str = "(*))";
    bool ans = checkValidString(str);
    cout << ans << endl;
}