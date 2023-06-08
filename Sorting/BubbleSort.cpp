#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> arr{10, 1, 7, 6, 14, 9};
    int num = arr.size();
    // Bubble Sort
    for (int round = 0; round < num - 1; round++){
        bool swapped = false;
        for (int j = 0; j < num - 1 - round; j++){
            if (arr[j] > arr[j + 1]){
                swapped = true;
                swap(arr[j], arr[j + 1]);
            }
        }
        if (swapped == false){
            cout<<"Array is sorted!!!!"<<endl;
            break;
        }
    }
    // Printing
    for (int i = 0; i < num; i++){
        cout << " " << arr[i];
    }
    cout << endl;
}