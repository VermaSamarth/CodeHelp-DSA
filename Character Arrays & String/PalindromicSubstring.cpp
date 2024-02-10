#include<iostream>
using namespace std;

int ExpandAroundIndex(string str, int i, int j){
    int count=0;
    while(i>=0 && j<str.length() && str[i]==str[j]){
        count++;
        i--;
        j++;
    }
    return count;
}

int countSubstrings(string s) {
    int len=s.length();
    int count=0;
    for(int i=0;i<len;i++){
        //Odd Length
        int oddAns = ExpandAroundIndex(s,i,i);
        count=count+oddAns;

        //Even Length
        int evenAns = ExpandAroundIndex(s,i,i+1);
        count=count+evenAns;
    }
    return count;
}

int main(){
    string str = "abccba";
    int ans = countSubstrings(str);
    cout << "Number of palindromic substrings: " << ans << endl;
}