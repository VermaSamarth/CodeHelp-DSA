#include <iostream>
#include <vector>
using namespace std;

// Recursive Solution
int Robbery(vector<int> &house, int n){
    if(n < 0)
        return 0;
    if(n == 0)
        return house[0];

    int includeHouse = Robbery(house, n - 2) + house[n];
    int excludeHouse = Robbery(house, n - 1) + 0;
    return max(includeHouse, excludeHouse);
}

int main(){
    vector<int> house = {1, 2, 3, 1};
    int n = house.size() - 1;
    cout << "Robbery Amount: " << Robbery(house, n) << endl;
}