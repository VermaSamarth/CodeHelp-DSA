#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    vector<int>arr = {5,4,7,5Top,9,6,7};
    int sum = 9;
    if(arr.size() < 2)
        cout << "-1" << endl;
    else{
        sort(arr.begin(), arr.end());
        int n1 = arr[0];
        int n2 = arr[1];
        if(n1 + n2 < sum)
            cout << n1*n2 << endl;
        else
            cout << "0" << endl;
    }
}