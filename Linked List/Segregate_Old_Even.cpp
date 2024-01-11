#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int data){
            this->data = data;
            this->next = NULL;
        }

        ~Node(){
            cout << "Destructor is called...." << endl;
        }
};

int findLength(Node* &head){
    Node* temp = head;
    int count = 0;
    while(temp != NULL){
        temp = temp->next;
        ++count;
    }
    return count;
}

void InsertStart(int data, Node* &head, Node* &tail){
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
    return;
}

void InsertEnd(int data, Node* &head, Node* &tail){
    if(head == NULL){
    Node* newNode = new Node(data);
    head = newNode;
    tail = newNode;
    return;
    }
    Node* newNode = new Node(data);
    tail->next = newNode;
    tail = newNode;
}

void InsertMiddle(int data, int position, Node* &head, Node* &tail){
    if(head == NULL){
    Node* newNode = new Node(data);
    head = newNode;
    tail = newNode;
    return;
    }

    if(position == 0){
        InsertStart(data, head, tail);
        return;
    }

    int len = findLength(head);
    if(position >= len){
        InsertEnd(data, head, tail);
        return;
    }

    int pos = 1;
    Node* prev = head;
    while(pos < position){
        prev = prev->next;
        ++pos;
    }
    Node* newNode = new Node(data);
    newNode->next = prev->next;
    prev->next = newNode;
    return;
}

void printList(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    return;
}

void SegregateLinkedList(Node* &head, Node* &tail){
    int len = findLength(head), count = 0;
    Node* temp = head;
    while(count < len){
        if(count%2 == 0){
        }
        temp = temp->next;
        ++count;
    }
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;

    InsertStart(41,head,tail);
    InsertStart(31,head,tail);
    InsertStart(20,head,tail);
    InsertStart(11,head,tail);
    InsertMiddle(50,4,head,tail);
    InsertMiddle(60,5,head,tail);
    InsertEnd(74,head,tail);
    InsertEnd(80,head,tail);
    InsertEnd(90,head,tail);
    InsertEnd(100,head,tail);

    cout << "Printing the linked list: " << endl;
    printList(head);
    cout << endl;

    cout << "Printing after segregation: "<< endl;
    SegregateLinkedList(head,tail);
    printList(head);
}