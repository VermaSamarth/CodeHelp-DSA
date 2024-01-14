#include<iostream>
#include<stack>
using namespace std;

int main(){
    string str;
    cout << "Enter the string: " << endl;
    cin >> str;

    stack<char> stk;

    for(int i = 0; i < str.length(); i++){
        stk.push(str[i]);
    }
    
    cout << "Reverse String: ";
    while(!stk.empty()){
        cout << stk.top();
        stk.pop();
    }
    cout << endl;
}