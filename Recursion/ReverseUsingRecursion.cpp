#include<iostream>
using namespace std;

void ReverseString(string&str, int start, int end){
    if(start > end)
        return;
    swap(str[start], str[end]);
    ReverseString(str,start+1,end-1);
    return;
}

int main(){
    string str = "abcdefgh";
    int start = 0;
    int end = str.length() - 1;
    ReverseString(str, start, end);
    cout << "Reverse of the string: " << str << endl;
}