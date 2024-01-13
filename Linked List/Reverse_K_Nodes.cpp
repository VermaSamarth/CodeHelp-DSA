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

// Find Length function
int findLength(Node* &head){
    Node* temp = head;
    int count = 0;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    return count;
}

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

Node* reverseKNodes(Node* head, int k){
    if(head == NULL){
        cout << "Linked list is empty...." << endl;
        return NULL;
    }

    if(k > findLength(head)){
        // cout << "Value is k is bigger than the length. /n Enter valid value..." << endl;
        return head;
    }

    Node* backward = NULL;
    Node* current = head;
    Node* forward = current->next;
    int count = 0;
    // Reversing the list in the set of K nodes.
    while(count < k){
        forward = current->next;
        current->next = backward;
        backward = current;
        current = forward;
        count++;
    }
    // Keeping the connection right
    if(forward != NULL){
        head->next = reverseKNodes(forward,k);
    }

    return backward;
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
    
    cout << "Reversed Linked List: " << endl;
    head = reverseKNodes(head, 6);
    printList(head);
}