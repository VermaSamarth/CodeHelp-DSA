#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    vector<int> a1 = {4,9,5,4};
    vector<int> a2 = {9,4,9,8,4};
    sort(a1.begin(), a1.end());
    sort(a2.begin(), a2.end());
    cout << "Intersections are: " << " ";
    int len1 = a1.size(), len2 = a2.size();
    int i = 0, j = 0;
    while((i<len1) && (j<len2)){
        if(a1[i] == a2[j]){
            cout << a1[i] << " ";
            i++;
            j++;
        }
        else if(a1[i] < a2[j])  
            i++;
        else
            j++;
    }
    cout << endl;
    return 0;
}