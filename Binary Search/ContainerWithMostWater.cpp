// You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

// Find two lines that together with the x-axis form a container, such that the container contains the most water.

// Return the maximum amount of water a container can store.

#include<iostream>
#include<vector>
using namespace std;

void calculateMaxWater(vector<int>& height, int& maxWater){
    int start = 0;
    int end = height.size() - 1;
    while(start < end){
    int currentWater = min(height[start],height[end]) * (end - start);
    maxWater = max(maxWater, currentWater);
    if(height[start] <= height[end])
        start++;
    else    
        end--;
    }
}

int main(){
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    int maxWater = INT_MIN;
    calculateMaxWater(height, maxWater);
    cout << "Max Water that can be filled: " << maxWater << endl;
}