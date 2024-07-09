#include<iostream>
#include<unordered_map>
using namespace std;

void MakeDigit(string&a, int&num, unordered_map<char,int>&ump, int i){
    if(i >= a.length())
        return;
    int d = ump[i];
    MakeDigit(a, num, ump, i+1);
    num = d*10 + num;
    return;
}

int main(){
    string a = "13";
    string b = "212";
    unordered_map<char,int> ump;
    ump['0'] = 0;
    ump['1'] = 1;
    ump['2'] = 2;
    ump['3'] = 3;
    ump['4'] = 4;
    ump['5'] = 5;
    ump['6'] = 6;
    ump['7'] = 7;
    ump['8'] = 8;
    ump['9'] = 9;
    int num1 = 0, num2 = 0;
    int i = 0;
    MakeDigit(a,num1,ump,i);
    MakeDigit(b,num2,ump,i);
    cout << num1 << " " << num2 << endl;
    cout << "Sum of numbers: " << num1 + num2 << endl;
}