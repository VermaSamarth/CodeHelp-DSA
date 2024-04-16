#include<iostream>
#include<deque>
using namespace std;

int main(){
    string str;
    cin >> str;
    int len = str.length();
    string opr = "";
    deque<int> deq;
    for(int i = 0; i < len; i++){
        if(isdigit(str[i]))
            deq.push_back((str[i]-'0'));
        else
            opr.push_back(str[i]);
    }
    for(auto  it: opr){
        int num1 = deq.front();
        deq.pop_front();
        int num2 = deq.front();
        deq.pop_front();
        if(it == 'A')
            num2 = num1 & num2;
        else if(it == 'B')
            num2 = num1 | num2;
        else    
            num2 = num1 ^ num2;
        
        deq.push_front(num2);
    }
    cout << deq.front() << endl;
}