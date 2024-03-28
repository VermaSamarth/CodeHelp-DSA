#include<iostream>
#include<vector>
using namespace std;

int trappingwater(vector<int> rain){
    int left = 0;
    int right = rain.size();
    int left_max = INT_MIN;
    int right_max = INT_MIN;
    int ans = 0;
    while(left < right){
        left_max = max(rain[left],left_max);
        right_max = max(rain[right], right_max);
        ans += (left_max < right_max) ? left_max - rain[left++] : right_max - rain[right--];
    }
    return ans;
}

int main(){
    int data, num;
    cin >> num;
    vector<int> rain;
    for(int i = 0; i < num; i++){
        cin >> data;
        rain.push_back(data);
    }
    cout << "Trapped water = " << trappingwater(rain) << endl;
}





/**
 * #include<iostream>
#include<vector>
using namespace std;

int trapping(vector<int> &ans){
    int l =0;
    int r = ans.size()-1;
    int ansi =0;
    int lmax = INT_MIN;
    int rmax = INT_MIN;

    while(l<r){
        lmax = max(lmax,ans[l]);
        rmax = max(rmax,ans[r]);
        ansi+=lmax<rmax?lmax-ans[l++]:rmax-ans[r--];
    }
    return ansi;
}
int main(){
    int n ;
    cin>>n;

    vector<int> ans;
    for(int i =0;i<n;i++){
        int num;
        cin>>num;
        ans.push_back(num);
    }

   int final =  trapping(ans);
   cout<<final<<endl;
}
*/