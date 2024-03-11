#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    string order = "bcafg", s = "abcd";
    unordered_map<char,int> chr;
    int i;
    for(i = 0; i < s.length(); i++){
        chr[s[i]]++;
    }
    string str = "";
    i = 0;
    while(i < order.length()){
        while(chr.find(order[i]) != chr.end() && chr[order[i]] != 0){
            str = str + order[i];
            chr[order[i]]--;
        }
        i++;
    }
    for(auto it:chr){
        if(it.second != 0)
            for(int i = 0; i < it.second; i++)
                str = str + it.first;
    }
    cout << str << endl;
    
}