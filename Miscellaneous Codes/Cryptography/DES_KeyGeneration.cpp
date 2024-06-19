#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main(){
    vector<vector<int>> permut_table = {{57, 49, 41, 33, 25, 17, 9}, 
                                        {1, 58, 50, 42, 34, 26, 18}, 
                                        {10, 2, 59, 51, 43, 35, 27}, 
                                        {19, 11, 3, 60, 52, 44, 36}, 
                                        {63, 55, 47, 39, 31, 23, 15}, 
                                        {7, 62, 54, 46, 38, 30, 22}, 
                                        {14, 6, 61, 53, 45, 37, 29}, 
                                        {21, 13, 5, 28, 20, 12, 4}};
    map<char,string> mapping;
    mapping['0'] = "0000";
    mapping['1'] = "0001";
    mapping['2'] = "0010";
    mapping['3'] = "0011";
    mapping['4'] = "0100";
    mapping['5'] = "0101";
    mapping['6'] = "0110";
    mapping['7'] = "0111";
    mapping['8'] = "1000";
    mapping['9'] = "1001";
    mapping['A'] = "1010";
    mapping['B'] = "1011";
    mapping['C'] = "1100";
    mapping['D'] = "1101";
    mapping['E'] = "1110";
    mapping['F'] = "1111";

    
    vector<string> key_bits(8);
    string key, str = "";
    // Inputting the key
    cout << "Enter the key: " << endl;
    cin >> key;

    // Converting key into 64 bit binary
    int i = 2;
    for(auto it: key){
        if(i != 0){
            str = str + mapping[it];
            i--;
        }
        else{
            key_bits.push_back(str);
            str = mapping[it];
            i = 1;
        }
    }
    key_bits.push_back(str);
    
    cout << endl << "Key in 64 bit binary: ";
    for(auto it: key_bits){
        cout << it << endl;
    }

    // Converting the 64 bit key into 56 bits
    map<int, char> new_map;
    i = 1;
    for(auto it: key_bits){
        for(auto itr: it){
            new_map[i] = itr;
            i++;
        }
    }
    

}