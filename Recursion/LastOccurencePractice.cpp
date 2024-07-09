#include<iostream>
using namespace std;

void findLastOccurence(string &str, char &chr, int&ans, int i){
    if(i >= str.length())
        return ;
    if(str[i] == chr){
        ans = i;
    }
    findLastOccurence(str, chr, ans, i+1);
    return;
}

void findLastOccurenceBack(string &str, char &chr, int&ans, int i){
    if(i < 0)
        return;
    if(str[i] == chr)
        ans = i;
    findLastOccurenceBack(str, chr, ans, i-1);
    return;
}
int main(){
    string str = "abcddefgd";
    char chr = 'f';
    int ans = -1;
    int i = 0;
    findLastOccurence(str, chr, ans, i);
    cout << "Last Occurence Position: " << ans << endl;
    int n = str.length() - 1;
    int a = -1;
    findLastOccurenceBack(str, chr, a, n);
    cout << "Last Occurence Position: " << a << endl;
}