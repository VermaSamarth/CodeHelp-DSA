#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    string str1, str2;
    cin >> str1 >> str2;
    sort(str1.begin(),str1.end());
    sort(str2.begin(),str2.end());
    bool flag = true;
    if(str1.length() != str2.length()){
        cout << !flag << endl;
    }
    else{
        for(int i = 0; i < str1.length(); i++){
            if(str1[i] != str2[i]){
                flag = false;
                break;
            }
        }
        cout << flag << endl;
    }
}