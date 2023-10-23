#include<iostream>
using namespace std;

void removeChar(string& str, char& chr,int& len, int index){
    if(index == len)
        return;
    if(str[index] == chr)
        str.erase(index,1);
    return removeChar(str,chr,len,index+1);
}
int main(){
    string str = "India is an amazing place";
    char chr = 'a';
    int len = str.length();
    int i = 0;
    cout << "Original string: " << str << endl;
    removeChar(str,chr,len,i);
    cout << "After removing: " << str << endl;
}