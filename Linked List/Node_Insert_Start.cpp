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
// Inserting a new node at the starting of the linked list
void insertAtHead(int data, Node* &head){
    // Step 1: New Node Creation
    Node* newNode = new Node(data);
    // Step 2: Next of new node
    newNode->next = head;
    // Step 3: Updating the new node as the head
    head = newNode;
}

void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << endl;
        temp = temp->next;
    }
}

int main(){
    Node* head = new Node(10);
    insertAtHead(20,head);
    insertAtHead(30,head);
    insertAtHead(40,head);
    insertAtHead(50,head);
    cout << "Printing the list: " << endl;
    print(head);
}