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

Node* middleNode(Node* &head){
    // Linked list empty
    if(head == NULL){
        cout << "Linked List is Empty....." << endl;
        return NULL;
    }
    // Linked list only 1 node
    if(head->next == NULL){
        return head;
    }

    Node* slow = head;
    Node* fast = head->next;
    while(slow != NULL && fast != NULL){
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
            slow = slow->next;
        }
    }
    return slow;
}

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

int main(){
    Node* head = NULL;
    InsertStart(10,head);
    InsertStart(30,head);
    InsertStart(50,head);
    InsertStart(70,head);
    InsertStart(90,head);
    InsertStart(110,head);
    InsertStart(130,head);
    InsertStart(150,head);

    cout << "Printing the Linked list: " << endl;
    printList(head);
    cout << "Middle of the Linked List: " << middleNode(head) -> data << endl;
}