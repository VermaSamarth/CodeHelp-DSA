// #include<iostream>
// #include<queue>
// using namespace std;

// int getTop(queue<int>&que1, queue<int>&que2){
//     int top;
//     while(!que1.empty()){
//         top = que1.front();
//         que2.push(top);
//         que1.pop();
//     }
//     int top_element = top;
//     while(!que2.empty()){
//         top = que2.front();
//         que1.push(top);
//         que2.pop();
//     }
//     return top_element;
// }

// int popQueue(queue<int>&que1, queue<int>&que2){
//     int top;
//     int len = que1.size();
//     while(!que1.empty() && len - 1 > 0){
//         top = que1.front();
//         que2.push(top);
//         que1.pop();
//         len--;
//     }
//     int pop_element = que1.front();
//     que1.pop();
//     while(!que2.empty()){
//         top = que2.front();
//         que1.push(top);
//         que2.pop();
//     }
//     return pop_element;
// }

// int main(){
//     int choice;
//     int data;
//     queue<int> que1;
//     queue<int> que2;
//     cin >> choice;
//     while(choice != -1){
//         if(choice == 1){
//             cin >> data;
//             que1.push(data);
//         }
//         else if(choice == 2){
//             cout << "Top element: " << getTop(que1,que2) << endl;
//         }
//         else if(choice == 3){
//             cout << "Pop: " << popQueue(que1,que2) << endl;
//         }
//         else{
//             if(que1.empty() == true)
//                 cout << "is empty: true" << endl;
//             else    
//                 cout << "is empty: false" << endl;
//         }
//         cin >> choice;
//     }
// }

#include<iostream>
#include<stack>
using namespace std;

int main(){
    int data, num, pop_num;
    stack<int> stk;
    cin >> num;
    for(int i = 0; i < num; i++){
        cin >> data;
        stk.push(data);
    }
    cin >> pop_num;
    cout << "Queue elements are: " << endl;
    while(pop_num > 0){
        cout << stk.top() << " ";
        stk.pop();
        pop_num--; 
    }
}