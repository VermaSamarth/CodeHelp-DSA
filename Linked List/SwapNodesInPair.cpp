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

        ~Node(){
            cout << "Node deleted successfully!!!" << endl;
        }
};

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

void printList(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    return;
}

Node* SwapNodes(Node* &head){
    if(head == nullptr || head->next == nullptr)
            return head;
        Node* newHead = nullptr;
        Node* previous = nullptr;
        Node* current = head;
        while(current->next != nullptr){
            Node* forward = current->next;

            if(forward->next != nullptr)
                current->next = forward->next;
           else
                current->next = nullptr;

            forward->next = nullptr;
            forward->next = current;

            if(newHead == nullptr)
                newHead = forward;
            else
                previous->next = forward;
                
            previous = current;
            if(current->next != nullptr)
                current = current->next;
        }
        return newHead;
}

int main(){
    Node* head = nullptr;
    InsertStart(7,head);
    InsertStart(6,head);
    InsertStart(5,head);
    InsertStart(4,head);
    InsertStart(3,head);
    InsertStart(2,head);
    InsertStart(1,head);

    cout << "Linked List before swapping nodes: " << endl;
    printList(head);
    Node* final = SwapNodes(head);
    cout << "Linked list after swapping nodes: " << endl;
    printList(final);
}