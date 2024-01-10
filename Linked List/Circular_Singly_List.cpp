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
            cout << "Node has been deleted...." << endl;
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
    cout << "Insertion starts......" << endl;
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        cout << "Insertion done..." << endl;
        return;
    }
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
    tail->next = head;
    cout << "Insertion done..." << endl;
    return;
}

void InsertEnd(int data, Node* &head, Node* &tail){
    cout << "Insertion starts......" << endl;
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        cout << "Insertion done..." << endl;
        return;
    }
    Node* newNode = new Node(data);
    tail->next = newNode;
    tail = newNode;
    tail->next = head;
    cout << "Insertion done..." << endl;
    return;
}

void InsertPosition(int data, int position, Node* &head, Node* &tail){
    cout << "Insertion starts......" << endl;
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    if(position == 0){
        InsertStart(data,head,tail);
        return;
    }

    int len = findLength(head);
    if(position >= len){
        InsertEnd(data,head,tail);
        return;
    }

    Node* previous = head;
    int pos = 1;
    while(pos != position){
        previous = previous->next;
        ++pos;
    }
    Node* current = previous->next;
    Node* newNode = new Node(data);
    newNode->next = current;
    previous->next = newNode;
    cout << "Insertion done..." << endl;
    return;
}

void printList(Node* &head){
    Node* temp = head->next;
    cout << head->data << " ";
    while(temp != head){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    return;
}

int main(){  
    cout << "Program starts...." << endl;
    Node* head = NULL;
    Node* tail = NULL;
    InsertStart(41,head,tail);
    InsertStart(31,head,tail);
    InsertStart(20,head,tail);
    InsertStart(11,head,tail);
    InsertPosition(50,0,head,tail);
    InsertPosition(60,6,head,tail);
    InsertEnd(74,head,tail);
    InsertEnd(80,head,tail);
    InsertEnd(90,head,tail);
    InsertEnd(100,head,tail);

    cout << "Printing the list: " << endl;
    printList(head);

    cout << "Tail->next : " << tail->next->data << endl;
    return 0;
}
