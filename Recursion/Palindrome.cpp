#include<iostream>
using namespace std;

bool CheckPalindrome(string&str, int start, int end){
    if(start == end)
        return true;
    if(str[start] == str[end]){
        return CheckPalindrome(str, start+1, end-1);
    }
    else{
        return false;
    }
}

int main(){
    string str = "racetcar";
    int start = 0, end = str.length()-1;
    bool ans = CheckPalindrome(str, start, end);
    cout << "Answer: " << ans << endl;
}