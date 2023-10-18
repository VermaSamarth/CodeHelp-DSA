#include<iostream>
using namespace std;
// Example of Head Recursion
void print(int number, int count){
    if(count == 0)
        return;
    print(number / 10 , --count);
    cout << (number % 10) << "  ";
}
int main(){
    // Print the digits of the number
    int num;
    cout << "Enter the Number: " << endl;
    cin >> num;
    // Code breaking at 0647
    // num=0547;
    // This is because when an integral literal starts with 0, it is interpreted as octal (base 8). Therefore it is getting converted to octal number printing that.
    if(num==0)
        cout << "0" << endl;
    int count = 0;
    // Counting the length of the number.
    for(int i=num;i!=0;i/=10){
        count++;
    }
    print(num,count);
}