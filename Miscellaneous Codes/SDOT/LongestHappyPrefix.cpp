#include<iostream>
#include<vector>
using namespace std;

string happystring(string prefix, string suffix, int len){
    int it = 1;
    while(suffix != "" && prefix != ""){
        if(prefix == suffix)
            return suffix;
        prefix.pop_back();
        int len = suffix.length();
        suffix = suffix.substr(it,len - it);
        // cout << "Prefix: " << prefix << " Suffix: " << suffix << endl;
    } 
    return "na";
}

int main(){
    string str;
    cin >> str;
    string prefix = "", suffix = "";
    for(int i = 1; i < str.length(); i++){
        suffix = suffix + str[i];
    }
    for(int i = 0; i < str.length() - 1; i++){
        prefix = prefix + str[i];
    }
    // cout << "Prefix: " << prefix << " Suffix: " << suffix << endl;
    string happy = happystring(prefix,suffix,str.length());
    cout << happy  << endl;
}