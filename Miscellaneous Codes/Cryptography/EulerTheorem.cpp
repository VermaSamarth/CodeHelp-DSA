#include<iostream>
#include<map>
#include<math.h>
using namespace std;


int phi_number(long long num){
    map<int,int> mapping;
    int phi = num;
    int div = 2;
    while(num != 1){
        if(num % div == 0){
            mapping[div]++;
            num = num / div;
        }
        else
            div++;
    }
    for(auto it: mapping){
        phi = phi * (double)(1.0 - 1.0/it.first);
    }
    cout << "Phi = " << phi << endl;
    return phi;
}

int main(){
    int a, n;
    cout << "Enter the a & n = ";
    cin >> a >> n;
    int phi = phi_number(n);
    long long ans = (long long)pow(a,phi) % n;
    if(ans != 1)
        cout << "Not co-prime." << endl;
    else    
        cout << "Co-prime." << endl;
}