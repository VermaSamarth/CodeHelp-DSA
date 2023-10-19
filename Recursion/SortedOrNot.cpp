#include<iostream>
using namespace std;

// Follow a simple rule -> Solve for one case, recusion will handle the reamining.

// Pass by refernce
bool checkSorted(int arr[], int& len, int i){
    // Base Condition
    // Check till length-1 because for nth element (n+1)th element won't exist.
    // If it is traversed to the last that means it is sorted.
    if(i >= len-1)
        return true;
    // Solve 1 case......
    // If the (i+1)th element smaller than ith then false -> Not in Ascending order.
    if(arr[i] > arr[i+1])
        return false;
    
    // Bakki recursion sambhal lenga.....
    return checkSorted(arr, len, i+1);
}

int main(){
    int arr[5] = {10,20,30,40,50};
    int len = 5;
    int index = 0;
    bool ans = checkSorted(arr, len, index);
    if(ans)
        cout << "Array is sorted!!!" << endl;
    else
        cout << "Array is not sorted!!!" << endl;
}