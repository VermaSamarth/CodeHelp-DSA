#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

int main(){
    int num1, num2, data;
    vector<int> arr1;
    vector<int> arr2;
    cin >> num1;
    for(int i = 0; i < num1; i++){
        cin >> data;
        arr1.push_back(data);
    }
    cin >> num2;
    for(int i = 0; i < num2; i++){
        cin >> data;
        arr2.push_back(data);
    }
    sort(arr1.begin(),arr1.end());
    int gcd = 1;
    // Uncomment the below line...............................................
    // gcd = __gcd(arr2[0],arr2[1]);
    for(auto it: arr2){
        // gcd = __gcd(gcd,it);
    }
    //........................................................................
    // cout << "GCD: " << gcd << endl; 
    int count = 0, flag;

    for(auto it:arr1){
        if(gcd % it != 0)
            count++;
        else
            break;
    }
    count = (count == num1) ? -1 : count;
    cout << count << endl;
}