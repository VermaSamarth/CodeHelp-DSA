#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    string str;
    cin >> str;
    sort(str.begin(),str.end());
    char chr = 'a';
    for(auto it:str){
        if(it != chr){
            cout << chr << endl;
            break;
        }
        chr++;
    }
}