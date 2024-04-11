#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

int countStudents(vector<int>& students, vector<int>& sandwiches) {
    queue<int> que;
        queue<int> stk;
        int zeroCount = 0, oneCount = 0;
        for(auto it: students){
            que.push(it);
            (it == 0) ? zeroCount++ : oneCount++;
        }  
            
        for(auto it: sandwiches)    stk.push(it);

        while(!que.empty()){
            if((stk.front() == 0 && zeroCount == 0) || (stk.front() == 1 && oneCount == 0))
                break;
            if(que.front() == stk.front()){
                (que.front() == 0) ? zeroCount-- : oneCount--;
                que.pop();
                stk.pop();
            }
            else if(que.front() != stk.front()){
                int data = que.front();
                que.pop();
                que.push(data);
            }
        }
        return que.size();
}
int main(){
    vector<int> students = {1,1,1,0,0,1};
    vector<int> sandwiches = {1,0,0,0,1,1};
    cout << "Counting the students..." << endl;
    int ans = countStudents(students,sandwiches);
    cout << "Ans: " << ans <<endl;
}