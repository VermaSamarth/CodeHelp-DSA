#include<iostream>
#include<unordered_map>
using namespace std;

int firstOccurence(string& str){
    unordered_map<char,int> counter;
    for(int i = 0; i < str.length(); i++){
        counter[str[i]]++;
    }

    for(int i = 0; i < str.length(); i++){
        if(counter[str[i]] == 1)
            return i;
    }
    return -1;
}

int main(){
    string str = "aryan";
    int ans = firstOccurence(str);
    cout << ans << endl;
}