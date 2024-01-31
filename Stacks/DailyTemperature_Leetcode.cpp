#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> dailyTemp(vector<int> &temperatures){
    stack<int> temp;
    stack<int> ind;
    vector<int> days;
    temp.push(0);
    ind.push(-1);
    int len = temperatures.size() - 1;
    for(int i = len; i >= 0; i--){
        cout << "Calculating...." << endl;
        while(temp.empty() == false && temperatures[i] >= temp.top()){
            cout << temp.top() << " is popped..." << endl;
            temp.pop();
            ind.pop();
        }
        temp.push(temperatures[i]);
        if(ind.empty()){
            ind.push(i);
            int num = ind.top();
            days.push_back(num - i);
        }
        else{
            int num = ind.top();
            days.push_back(num - i);
            ind.push(i);
        }
        cout << temp.top() << " is current top..." << endl;
    }

    int start = 0;
    while(start <= len){
        swap(days[start],days[len]);
        start++;
        len--;
    }
    return days;
}

int main(){
    vector<int> temperatures = {73,74,75,71,69,72,76,73};
    vector<int> days = dailyTemp(temperatures);
    cout << "Next warmer days: ";
    for(int i = 0; i < days.size(); i++){
        cout << days[i] << " ";
    }
    cout << endl;
    return 0;
}