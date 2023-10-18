// Number of ways to climb to the top of the stairs.
// You can either take 1 step at a time or 2 steps at a time.
#include<iostream>
using namespace std;

int ClimbStairs(int num){
    // Base Condition
    if(num==0 || num==1)
        return 1;
    // Number of ways of reaching 0th stair: 1 (Because you are already standing on the 0th stair)
    // If we say that there are 0 ways to reach there then it is illogical. 
    int ans = ClimbStairs(num-1) + ClimbStairs(num-2);
    return ans;
}
int main(){
    int stairs;
    cout<<"Enter the number of stairs: "<<endl;
    cin>>stairs;
    cout<<"Number of ways to reach the top of stairs: "<<ClimbStairs(stairs)<<endl;
}