#include<iostream>
#include<vector>
using namespace std;

void printVector(vector<int> arr);

int main(){
    int slen, keylen, textlen;

    // State Array Inputs
    cout << "Enter the size of the state vector: " << endl;
    cin >> slen;
    vector<int> s(slen);
    cout << "Enter the state vector: " << endl;
    for(int i = 0; i < slen; i++)
        cin >> s[i];

    // Key Array inputs
    cout << "Enter the key size: " << endl;
    cin >> keylen;
    vector<int> keys(keylen);
    cout << "Enter the key vector: " << endl;
    for(int i = 0; i < keylen; i++)
        cin >> keys[i];

    // Plainetext Array inputs
    cout << "Enter the plaintext size: " << endl;
    cin >> textlen;
    cout << "Enter the plaintext vector: " << endl;
    vector<int> plaintext(textlen);
    for(int i = 0; i < textlen; i++)
        cin >> plaintext[i];

    // Constructing the T_Array with keys
    vector<int> t;
    for(int i = 0; i < slen; i++)
        t.push_back(keys[i % keylen]);
    
    // KEY GENERATION
    int j = 0, i;
    for(i = 0; i < slen; i++){
        j = (j + s[i] + t[i]) % slen;
        swap(s[i], s[j]);
    }
    cout << "State Vector after key generation: ";
    printVector(s);
    cout << endl;

    // STREAM GENERATION
    vector<int> arr;
    j = 0; i = 0;
    while(keylen--){
        i = (i + 1) % slen;
        j = (j + s[i]) % slen;
        swap(s[i], s[j]);
        int temp = (s[i] + s[j]) % slen;
        arr.push_back(s[temp]);
    }

    // ENCRYPTION DECRYPTION
    vector<int> cipher;
    for(i = 0; i < textlen; i++){
        cipher.push_back(arr[i] ^ plaintext[i]);
    }
    cout << "Cipher Text after Encryption: ";
    printVector(cipher); 
    cout << "Text after Decryption: ";
    printVector(plaintext);
}

void printVector(vector<int> arr){
    for(auto it: arr)
        cout << it << " ";
    cout << endl;
    return;
}