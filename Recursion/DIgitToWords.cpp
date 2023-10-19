#include<iostream>
#include<vector>
using namespace std;

void printWords(int& num, vector<string>& arr){
    if(num==0)
        return;
    int index = num%10;
    num=num/10;
    printWords(num,arr);
    cout << arr[index] << " " ;
}

int main(){
    vector<string> arr = {"zero","one","two","three","four","five","six","seven","eight","nine"};
    int num;
    cout << "Enter the number: " << endl;
    cin >> num;
    printWords(num,arr);
    cout << endl;
}