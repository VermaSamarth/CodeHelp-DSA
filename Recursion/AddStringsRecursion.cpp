#include<iostream>
#include<algorithm>
using namespace std;

void AddStringRecursion(string&num1, string&num2, int p1, int p2, int carry, string&ans){
    if(p1 < 0 && p2 < 0){
        if(carry != 0)
            ans.push_back(carry + '0');
        return;
    }
    int n1 = (p1 >= 0) ? num1[p1] - '0' : 0;
    int n2 = (p2 >= 0) ? num2[p2] - '0' : 0;
    int csum = n1 + n2 + carry;
    int digit = csum % 10;
    carry = csum / 10;
    ans.push_back(digit + '0');
    AddStringRecursion(num1, num2, p1 - 1, p2 - 1, carry, ans);
    return; 
}

int main(){
    string num1 =    "123456";
    string num2 = "123456789";
    int len1 = num1.length();
    int len2 = num2.length();
    string ans = "";
    AddStringRecursion(num1, num2, len1-1, len2-1, 0, ans);
    reverse(ans.begin(), ans.end());
    cout << "Sum of the two number = " << ans << endl;
}