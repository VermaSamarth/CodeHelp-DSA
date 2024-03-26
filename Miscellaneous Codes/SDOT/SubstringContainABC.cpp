#include<iostream>
#include<unordered_map>
using namespace std;

bool checkContaining(string str){
    unordered_map<char,int> ump;
    for(auto it:str)
        ump[it]++;
    return (ump.size() == 3) ? true : false;
}

int main(){
    string str;
    cin >> str;
    int count = 0;
    for(int i = 0; i <= str.length() - 3; i++){
        for(int j = 0; j <= str.length() - 3 - i; j++){
            string s = str.substr(i,3+j);
            if(checkContaining(s)){
                cout << s << endl;
                count++;
            }
        }
    }
    cout << count  << endl;
}