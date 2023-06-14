#include<iostream>
#include<string.h>
using namespace std;

bool compareString(string str1, string str2){
    if(str1.length()!=str2.length()){
        return false;
    }
    for(int i=0;i<str1.length();i++){
        if(str1[i]!=str2[i]){
            return false;
        }
    }
    return true;
}


int main(){
    string str1="Love",str2="Love";
    cout<<"Equal Strings ----> "<<compareString(str1,str2)<<endl;
}