/* The Binary number system only uses two digits, 0 and 1 and the number system can be called binary string. You are required to implement the following function:
int OperationsBinaryString(char* str);
The function accepts a string str as its argument. The string str consists of binary digits separated with an alphabet as follows:
– A denotes AND operation
– B denotes OR operation
– C denotes XOR Operation

You are required to calculate the result of the string str, scanning the string to right taking one operation at a time, and return the same.
*/

#include<iostream>
#include<string>
using namespace std;

string BinaryComputation(string&str){
    auto len = str.length();
    int num1, num2;
    int ans;
    for(auto i = 0; i < len - 2; i++){
        if(str[i] == '1')   num1 = 1;
        else    num1 = 0;
        char opr = str[i+1];
        if(str[i+2] == '1') num2 = 1;
        else    num2 = 0;

        if(opr == 'A')
            num2 = num1 & num2;
        if(opr == 'B')
            num2 = num1 | num2;
        if(opr == 'C')
            num2 = num1 ^ num2;
        ans = num2;
        str[i+2] = char(num2);
    }
    return to_string(ans);
}

int main(){
    string str;
    cin >> str;
    cout << BinaryComputation(str) << endl;
}