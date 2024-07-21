/*
Given two integers s and d. 
The task is to find the smallest number such that the sum of its digits is s and the number of digits in the number are d. 
Return a string that is the smallest possible number. If it is not possible then return -1.
*/
#include<iostream>
#include<string>
using namespace std;

string FindSmallestNumber(int&s, int&d){
    string ans = "";
    // Checking if the number cannot be formed?
    if((d*9) < s)
        return "-1";
    
    for(int i = d-1; i >= 0; i--){
        // If the s > 9, then we will add 9 to the back of the string.
        if(s > 9){
            ans = "9" + ans;
            s = s - 9;
        }
        // If the s < 9, then we check the following conditions.
        else{
            if(i == 0)  // If s < 9 & only one digit location left, then insert that value of s.
                ans = to_string(s) + ans;
            else{
                if(s == 1)  // If s = 1 & more than 1 digit location is left, then insert 0.
                    ans = "0" + ans;
                else{       // Calculate the s-1 and insert in the digit location.
                    int rem = s - 1;
                    s = 1;
                    ans = to_string(rem) + ans;
                }
            }
        }
    }
    return ans;
}

int main(){
    int s, d;
    cout << "Enter the sum value and the number of digits: " << endl; 
    cin >> s >> d;
    string ans = FindSmallestNumber(s,d);
    cout << "Smallest Number = " << ans << endl;
}