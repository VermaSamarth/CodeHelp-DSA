#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

bool reverseString(string str){
    string str1 = str;
    reverse(str1.begin(),str1.end());
    return (str1 == str) ? true : false;
}

int main(){
    string str, str1;
    cin >> str;
    if(reverseString(str)) cout << str << endl;
    string s = str;
    int i = str.length() - 1;
    int len = str.length();
    s = str[i] + str;
    i--;
    while(!reverseString(s)){
        string st = str.substr(i,len - i);
        reverse(st.begin(),st.end());
        s = st + str;
        i--;
    }
    cout << s << endl;
}