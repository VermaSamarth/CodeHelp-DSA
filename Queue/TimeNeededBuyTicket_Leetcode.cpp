#include<iostream>
#include<queue>
using namespace std;

int main(){
    vector<int> tickets = {5,1,1,1};
    int k = 0;
    queue<int> que;
    int total_time = 0, i = 0;
    while(tickets[k] != 0){
        if(tickets[i] != 0){
            tickets[i]--;
            total_time++;
        }
        i++;
        if(tickets[k] == 0)
            break;
        if(i == tickets.size())
            i = 0;
    }
    cout << "Total time: " << total_time << endl;
}