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

// Function to insert node in the linked list
void InsertStart(int data, Node* &head){
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        return;
    }
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
    return;    
}

// Function to print the linked list
void printList(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    return;
}

void RemoveDuplicates(Node* &head){
    if(head == NULL){
        cout << "Linked List is empty..." << endl;
        return;
    }
    if(head->next == NULL){
        return;
    }

    Node* current = head;
    Node* forward = current->next;
    while(forward != NULL){
        if(current->data == forward->data){
            Node* temp =forward;
            current->next = forward->next;
            forward = current->next;
            temp->next = NULL;  
            delete temp;
        }
        else{
            current = current->next;
            forward = forward->next;
        }
    }
}

int main(){
    Node* head = NULL;
    InsertStart(70,head);
    InsertStart(70,head);
    InsertStart(60,head);
    InsertStart(60,head);
    InsertStart(50,head);
    InsertStart(40,head); 
    InsertStart(40,head);
    InsertStart(30,head);
    InsertStart(20,head);
    InsertStart(20,head);
    InsertStart(10,head);
    InsertStart(10,head);
    InsertStart(10,head);

    cout << "Printing the Linked list: " << endl;
    printList(head);

    RemoveDuplicates(head);

    cout << "Linked List after removing duplicates: " << endl;
    printList(head);
}