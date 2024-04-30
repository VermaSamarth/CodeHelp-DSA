#include<iostream>
#include<math.h>
#include<map>
using namespace std;

// Function to calculate the value of phi.
int calculatePhi(int num);

int main(){
    int p, q, e, m;
    cout << "Enter the value of p, q, e and m: " << endl;
    cin >> p >> q >> e >> m;
    // Calculating the value of n.
    int n = q * p;
    // Calculating the value of phit_n.
    int phi_n = (p - 1) * (q - 1);
    // Calculated value of phi
    int phi_phi_n = calculatePhi(phi_n);

    double d = (int)pow(e, phi_phi_n - 1) % phi_n; 

    // Encryption Decryption Process
    long long encrypt = (long long)pow(m, e) % n;
    long long decrypt = (long long)pow(encrypt, d) % n;
    cout << "Encryption: " << encrypt << "  Decryption: " << m << endl;
}

int calculatePhi(int num){
    map<int,int> mapping;
    int div = 2, ans = num;
    while(num != 1){
        if(num % div == 0){
            num = num / div;
            mapping[div]++;
        }
        else
            div++;
    }
    for(auto it: mapping){
        ans = ans * (1.0 - 1.0/(it.first));
    }
    return (int)ans;
}
