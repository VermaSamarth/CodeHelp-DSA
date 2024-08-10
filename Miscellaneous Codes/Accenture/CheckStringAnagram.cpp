#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main(){
    string str1 = "Listen";
    string str2 = "Solent";
    if(str1.length() == str2.length()){
        transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
        transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
        sort(str1.begin(), str1.end());
        sort(str2.begin(), str2.end());
        int ans = str1.compare(str2);
        if(ans == 0)
            cout << "Anagram Strings." << endl;
        else    
            cout << "Not the Anagram Strings." << endl;
    }
    else    
        cout << "Not the Anagram Strings." << endl;
}