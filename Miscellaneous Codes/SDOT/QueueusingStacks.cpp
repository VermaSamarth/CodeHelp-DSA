#include<iostream>
#include<stack>
using namespace std;

int main(){
    int data, num, numpop;
    stack<int> stk1;
    stack<int> stk2;
    cin >> num;
    for(int i = 0; i < num; i++){
        cin >> data;
        stk1.push(data);
    }
    cin >> numpop;
    int len = stk1.size();
    int i = 0, top;
    while(i < len - numpop){
        top = stk1.top();
        stk2.push(top);
        stk1.pop();
        i++;
    }
    while(!stk1.empty())
        stk1.pop();
    cout << "Queue elements are:" << endl;
    while(!stk2.empty()){
        cout << stk2.top() << " ";
        stk2.pop();
    }
}