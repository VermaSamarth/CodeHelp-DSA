#include<iostream>
using namespace std;

int lastOccurence(string& str, char& chr, int pos){
    if(pos < 0)
        return -1;
    if(str[pos] == chr)
        return pos;
    else 
        return lastOccurence(str,chr,pos-1);
}

int main(){
    string str;
    char chr;
    cout << "Enter the string: " << endl;
    cin >> str;
    cout << "Enter the character: " << endl;
    cin >> chr;

    int len = str.length();
    int index = lastOccurence(str,chr,len-1);
    cout << "Last Occurence: " << index << endl;
}