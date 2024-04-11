#include<iostream>
#include<string>
using namespace std;

int main(){
    string str;
    cin >> str;
    
    int sum = 0, num;
    for(int i = 0; i < str.length(); i++){
        if(islower(str[i])){
            num = str[i] - 'a';
            sum = sum + (97 + num);
        }
        else{
            num = str[i] - 'A';
            sum = sum + (65 + num);
        }
    }
    cout << (float)sum/str.length() << endl;
}