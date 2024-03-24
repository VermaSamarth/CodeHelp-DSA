#include<iostream>
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
        head->next = nullptr;
    }
    else{
        tail->next = newNode;
        tail = tail->next;
    }
}

void printLinkedlist(Node* temp){
    while(temp != nullptr){
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

Node* RotateList(Node* head, int k){
    if(head == nullptr || head->next == nullptr || k == 0)
        return head;
    for(int i = 0; i < k; i++){
        Node* temp = head;  
        Node* previous = nullptr;
        while(temp->next != nullptr){
            previous = temp;
            temp = temp->next;
        }
        previous->next = nullptr;
        temp->next = nullptr;
        temp->next = head;
        head = temp;
    }
    return head;
}

int main(){
    Node* head = nullptr;
    Node* tail = nullptr;
    int num, data, k;
    cin >> num;
     for(int i = 0; i < num; i++){
        cin >> data;
        InsertNode(head,tail,data);
    }
    cin >> k;
    printLinkedlist(head);
    k = k % num;
    Node* ans = RotateList(head,k);
    printLinkedlist(ans);
}