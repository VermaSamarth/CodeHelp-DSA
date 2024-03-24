#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node(int data){
            this->data = data;
            this->next = nullptr;
        }
};

void InsertNode(Node* &head, Node* &tail, int data){
    Node* newNode = new Node(data);
    if(head == nullptr){
        head = tail = newNode;
        // head->next = tail;
    }
    else{
        tail->next = newNode;
        tail = tail->next;
    }
}

void printLists(vector<Node*> list, int num){
    for(int i = 0; i < num; i++){
        Node* temp = list[i];
        while(temp != nullptr){
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
}

Node* mergeList(vector<Node*> list){
    vector<int> arr;
    if(list.size() == 1)
        return list[0];
     for(int i = 0; i < list.size(); i++){
        Node* temp = list[i];
        while(temp != nullptr){
            arr.push_back(temp->data);
            temp = temp->next;
        }
    }
    sort(arr.begin(),arr.end());
    Node* head = nullptr;
    Node* tail = nullptr;
    for(int i = 0; i < arr.size(); i++){
        InsertNode(head,tail,arr[i]);
    }
    return head;
}

void printLinkedlist(Node* temp){
    // if(temp->next == nullptr){
    //     cout << temp->data << "->NULL" << endl;
    //     return;
    // }
    while(temp != nullptr){
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main(){
    int num,data;
    cin >> num;
    vector<Node*> list;
    for(int i = 0; i < num; i++){
        Node* head = nullptr;
        Node* tail = nullptr;
        cin >> data;
        while(data != -1){
            InsertNode(head, tail, data);
            cin >> data;
        }
        list.push_back(head);
    }
    // printLists(list,num);
    Node* anshead = mergeList(list);
    printLinkedlist(anshead);
}