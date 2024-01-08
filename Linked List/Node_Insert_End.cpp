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
};

void InsertAtHead(int data, Node* &tail, Node* &head){
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
    if(head->next == NULL)
        tail = newNode;
}

void InsertAtTail(int data, Node* &tail, Node* &head){
    Node* newNode = new Node(data);
    if(tail == NULL){
        tail = newNode;
        head = newNode;
    }
    else{
        tail->next = newNode;
    }
    tail = newNode;
}

void printList(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << endl;
        temp = temp->next;
    }
}

void InsertStart(int data, Node* &head, Node* &tail){
    // If the Linked list is empty
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    // If the linked list is not empty 
    Node* newNode = new Node(data);
    newNode->next =  head;
    head = newNode;
}

void InsertEnd(int data, Node* &head, Node* &tail){
    // If the list is empty
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    // If the list not empty
    Node* newNode = new Node(data);
    tail->next = newNode;
    tail = newNode;
}

int findLength(Node* &head){
    int count=0;
    Node* temp = head;
    while(temp != NULL){
        temp = temp->next;
        count++;
    }
    return count;
}

void InsertPosition(int data, int position, Node* &head, Node* &tail){
    // If the list is empty
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    // If the position is 0 or the start
    if(position == 0){
        InsertStart(data,head,tail);
        return;
    }

    // If position is end or greater
    int len = findLength(head);
    if(position >= len){
        InsertEnd(data,head,tail);
        return;
    }
    // Finding the position
    int count = 1;
    Node* prev = head;
    while(count != position){
        prev = prev->next;
        count++;
    }
    Node* curr = prev->next;

    Node* newNode = new Node(data);
    newNode->next = curr;
    prev->next = newNode;


}

int main(){
    Node* head = NULL;
    Node* tail = NULL;
    // InsertAtHead(10,tail,head);
    // InsertAtHead(30,tail,head);
    // InsertAtHead(50,tail,head);
    // InsertAtHead(70,tail,head);
    // InsertAtTail(90,tail,head);
    // InsertAtTail(110,tail,head);
    // InsertAtTail(130,tail,head);
    // InsertAtTail(150,tail,head);
    InsertStart(10,head,tail);
    InsertStart(30,head,tail);
    InsertStart(50,head,tail);
    InsertStart(70,head,tail);
    InsertEnd(90,head,tail);
    InsertEnd(110,head,tail);
    InsertEnd(130,head,tail);
    InsertEnd(150,head,tail);
    cout << "Printing the Linked list: " << endl;
    printList(head);

    InsertPosition(200,10,head,tail);
    cout << "Printting at insertion in middle" << endl;
    printList(head);
}