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
    if(head == nullptr)
        head= tail = newNode;
    else{
        tail->next = newNode;
        tail = tail->next;
    }
}

Node* reverse(Node* head, int k){
    int it = 0;
    Node* left = nullptr;
    Node* curr = head;
    Node* right = head;
    while(it < k && curr != nullptr){
        it++;
        right = curr->next;
        curr->next = left;
        left = curr;
        curr = right;
    }
    return (it == k) ? left : head;
}

Node* reverseKNodes(Node* head, int k){
    Node* anshead = new Node(0);
    Node* anstail = nullptr;
    anshead = anstail;
    int i = 0;
    Node* temp = head;
    Node* start = head;
    while(temp != nullptr){
        if(i == k){
            i = 0;
            anstail->next = reverse(start,k);
            start = temp;
        }
        i++;
    }
    anshead = anshead->next;
    return anshead;
}

void printLinkedlist(Node* temp){
    while(temp != nullptr){
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
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
    cout << "Values Inserted" << endl;
    printLinkedlist(head);
    Node* ans = reverseKNodes(head,k);
    printLinkedlist(ans);
}