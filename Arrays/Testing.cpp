#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// int main(){
//     double arr[10] = {1.0, 2.0};
//     int brr[10];
//     for(int i = 0; i < 10; i++){
//         cout << arr[i] << " ";
//     }
//     cout << endl;
//     cout << "Array with no values: ";
//     for(int i = 0; i < 10; i++){
//         cout << brr[i] << " ";
//     }
//     cout << endl;
// }

// BINARY_SEARCH Function

// int main(){
//     vector<int> a = {1,2,3,4,5,6,7};
//     int b[] = {1,2,3,4,5,6,7};
//     auto ans1 = binary_search(a.begin(), a.end(),6);
//     int s = sizeof(b)/sizeof(b[0]);
//     auto ans2 = binary_search(b, b+s, 6);
//     cout << ans1 << " " << ans2 << endl;
// }

// LOWER_BOUND & UPPER_BOUND

// int main(){
//     vector<int>arr = {1,2,4,4,4,4,4,5,6,6,7,8,9,9,9,10};
//     int num1 = 4, num2 = 9;
//     auto first_occ = lower_bound(arr.begin(), arr.end(), num1);
//     auto last_occ = upper_bound(arr.begin(), arr.end(), num1);
//     cout << "First: " << first_occ - arr.begin() << " Last: " << last_occ - arr.begin() - 1 << endl; 
//     cout << "Total Occurence: " <<(last_occ - arr.begin()-1) - (first_occ - arr.begin()) + 1 << endl;
// }


int main(){
    vector<int> arr = {1,1,2,2,3,3,4,4,5,6,6,7,7,8,8};
    for(int i = 0; i < arr.size(); i++){
        auto first = lower_bound(arr.begin(), arr.end(), arr[i]);
        auto last = upper_bound(arr.begin(), arr.end(), arr[i]);
        int num_occ = (last - arr.begin() - 1) - (first - arr.begin()) + 1;
        if(num_occ & 1){
            cout << arr[i] << endl;
            break;
        } 
        else{
            i += num_occ - 1;
        }
    }
}