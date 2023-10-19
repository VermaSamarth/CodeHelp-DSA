#include<iostream>
using namespace std;

int cutSegments(int n, int& x, int& y, int& z){
    // Base Case
    if(n == 0)
        return 0;
    if(n < 0)
        return INT_MIN;
    int ans1 = cutSegments(n-x, x, y, z)+1;
    int ans2 = cutSegments(n-y, x, y, z)+1;
    int ans3 = cutSegments(n-z, x, y, z)+1;

    return max(ans1,max(ans2,ans3));
}
int main(){
    int rod = 7;
    int x = 5;
    int y = 2;
    int z = 2;
    int ans = cutSegments(rod,x,y,z);
    if(ans < 0)
        ans = 0;
    cout << "Answer: " << ans << endl;
}