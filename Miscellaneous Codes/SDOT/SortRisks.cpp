#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> arr;
    int num, data, count0, count1, count2;
    cin>>num;
    for(int i = 0; i <  num; i++){
        cin >> data;
        if(data >= 0 && data < 3)  arr.push_back(data);
    }
    int start = 0, end = arr.size() - 1;
    int it = 0;
    while(it < arr.size()){
        if(arr[it] == 0 && it > start)    
            swap(arr[it],arr[start++]);
        else if(arr[it] == 2 && it < end)   
            swap(arr[end--],arr[it--]);
        it++;
    }
    for(auto it: arr)
        cout << it << " ";
    cout << endl;
}