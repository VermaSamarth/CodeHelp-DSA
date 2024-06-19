#include<iostream>
using namespace std;

int main(){
    string str = "aaabbb";
    char s = str[0];
    for(int i = 1; i < str.length(); i++){
        s = s ^ str[i];
    }
    cout << s << endl;
    cout << s + "0" << endl;
}