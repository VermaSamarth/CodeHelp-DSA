#include<iostream>
#include<vector>
using namespace std;
int main(){
    int number;
    cout<<"Enter the number: "<<endl;
    cin>>number;

    vector<bool> prime(number,true);        // Initially all the numbers are set to true.
    prime[0]=prime[1]=false;            // Only 0 and 1 set as false because they are non-prime.

    int count=0;
    for(int i=2;i<number;i++){
        if(prime[i]){
            count++;
            int j = 2 * i;
            while(j<number){
                prime[j]=false;
                j+=i;
            }
        }
    }
    cout<<"Number of prime: "<<count<<endl;
}