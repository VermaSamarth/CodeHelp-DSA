#include<iostream>
using namespace std;
int main(){
    char chr[10]="BABBAR";
    char* c=chr;
    cout<<chr<<endl;
    cout<<&chr<<endl;
    cout<<chr[0]<<endl;

    cout<<c<<endl;
    cout<<&c<<endl;
    cout<<*c<<endl;

    //Example 
    char name[10]="SheruBano";
    char* cptr=&name[0];
    cout<<name<<endl;
    cout<<&name<<endl;
    cout<<*(name+3)<<endl;
    cout<<cptr<<endl;
    cout<<&cptr<<endl;
    cout<<*(cptr+3)<<endl;
    cout<<*cptr<<endl;
    cout<<cptr+2<<endl;
    cout<<cptr+8<<endl;
}