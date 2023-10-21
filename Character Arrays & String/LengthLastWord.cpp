#include<iostream>
using namespace std;

int lengthOfLastString(string& s){
    s = " " + s;
    int length = s.length();
    int start, end;
    // Index of the last alphabet.
    for(int i = length - 1; i >= 0; i--){
        if(isalpha(s[i])){
            end = i;
            break;
        }
    }

    // Index of whitespace 
    for(int i = length - 1; i >= 0; i--){
        if(s[i] == ' '){
            start = i;
            break;
        }
    }
    return end - start;
}

int main(){
    string str;
    cout << "Enter the string: " << endl;
    cin >> str;
    int len = lengthOfLastString(str);
    cout << "Length of the last word: " << len << endl;
}