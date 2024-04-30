#include<iostream>
#include<math.h>
using namespace std;

int main(){
    int q, alpha, private_a, private_b;
    cout << "Enter the prime number q: " << endl;
    cin >> q;
    cout << "Enter the primitive root of q -> alpha: " << endl;
    cin >> alpha;
    cout << "Enter the private keys of A and B respectively: " << endl;
    cin >> private_a >> private_b;

    long long public_a = (long long)pow(alpha, private_a) % q; 
    long long public_b = (long long)pow(alpha, private_b) % q;

    int key1 = (long long)pow(public_b, private_a) % q;
    int key2 = (long long)pow(public_a, private_b) % q;

    cout << "Public Key A = " << public_a << "   Public Key B = " << public_b << endl;
    cout << "Key 1 = " << key1 << "   Key 2 = " << key2 << endl;
}



