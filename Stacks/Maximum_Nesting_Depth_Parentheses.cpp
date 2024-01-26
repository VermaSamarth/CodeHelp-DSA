#include <iostream>
#include <stack>
using namespace std;

int main()
{
    string s = "(1+(2*3)+((8)/4))+1";
    stack<char> stk;
    int count = 0;
    int maxcount = 0;
    for (int i = 0; i < s.length(); i++){
        if (s[i] == '('){
            stk.push('(');
            count++;
            maxcount = max(maxcount, count);
        }
        else if (s[i] == ')'){
            stk.pop();
            count--;
        }
        else if (s[i] == '1' || s[i] == '2' || s[i] == '3' || s[i] == '4' || s[i] == '5' || s[i] == '6' || s[i] == '7' || s[i] == '8' || s[i] == '9' || s[i] == '0' || s[i] == '/' || s[i] == '+' || s[i] == '-' || s[i] == '*'){
            maxcount = max(maxcount, count);
        }
    }
    cout << "String: " << s << endl;
    cout << "Maximum nested parenthesis: " << maxcount << endl;
}