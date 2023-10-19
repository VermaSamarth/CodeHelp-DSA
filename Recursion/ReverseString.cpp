#include<iostream>
using namespace std;

void reverseString(string& str, int start, int end){
    if(start > end)
        return;
    swap(str[start],str[end]);
    reverseString(str,start+1,end-1);
}

int main(){
    string str;
    cout << "Enter the string: " << endl;
    cin >> str;
    int len = str.length();
    reverseString(str,0,len-1);
    cout << "Reverse: " << str << endl;
}