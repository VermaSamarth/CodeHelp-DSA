#include<iostream>
using namespace std;

string checkPalin(string str, int start, int end){
    if(start > end)
        return str;
    swap(str[start],str[end]);
    checkPalin(str,start+1,end-1);
    return str;
}
int main(){
    string str = "naman";
    int start = 0;
    int end = str.length() - 1;
    string reverse = checkPalin(str,start,end);
    if(str == reverse)
        cout << "It is a Palindrome String." << endl;
    else
        cout << "It is not a Palindrome String." << endl;
}