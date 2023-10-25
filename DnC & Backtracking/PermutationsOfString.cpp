#include<iostream>
using namespace std;

void printPermutation(string& str, int i){ 
    // Base Case
    if(i >= str.length()){
        // Printing the created Permutation
        cout << str << " ";
        return;  
    }

    // Swapping
    for(int j = i; j < str.length(); j++){
        // Swapping : Making new Permutations
        swap(str[i],str[j]);

        // Recursive Call
        printPermutation(str,i+1);

        // Backtracking : Recreate the original input
        swap(str[i],str[j]);
    }
}

int main(){
    string str = "abc";
    int len = str.length();
    int i = 0;
    cout << "Permutations of the String : " ;
    printPermutation(str,i);
}