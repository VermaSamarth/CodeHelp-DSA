#include <iostream>
using namespace std;

int x = 5;      // Global Variable

int main(){
    int x = 20;     // Local Variable   
    cout << x << endl;
    cout << ::x << endl;        // Access global in scope
}