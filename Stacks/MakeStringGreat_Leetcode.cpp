#include <iostream>
#include <stack>
using namespace std;

int main()
{
    string str = "abBAcC";
    stack<char> stk;

    cout << "Original String: " << str << endl;
    for (int i = 0; i < str.length(); i++){
        if (!stk.empty() && isupper(stk.top()) && islower(str[i]) && stk.top() == toupper(str[i])){
            cout << "Popped - UPPER -> LOWER" << endl;
            stk.pop();
        }
        else if (!stk.empty() && islower(stk.top()) && isupper(str[i]) && stk.top() == tolower(str[i])){
            cout << "Popped - LOWER -> UPPER" << endl;
            stk.pop();
        }
        else{
            cout << "Pushed...." << endl;
            stk.push(str[i]);
        }
    }
    str = "";
    while (!stk.empty()){
        str = stk.top() + str;
        stk.pop();
    }
    cout << "Modified String: " << str << endl;
}