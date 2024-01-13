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

void SortZeroOneTwo(Node* &head){
    if(head == NULL){
        cout << "List is empty...." << endl;
        return;
    }
    if(head->next == NULL){
        cout << "Already sorted as only 1 node present...." << endl;
        return;
    }
    int countZero = 0, countOne = 0, countTwo = 0;
    Node* temp = head;
    while(temp != NULL){
        if(temp->data == 0)
            ++countZero;
        if(temp->data == 1)
            ++countOne;
        if(temp->data == 2)
            ++countTwo;
        temp = temp->next;
    }
    
    temp = head;
    while(temp != NULL){
        if(countZero != 0){
            temp->data = 0;
            --countZero;
        }
        else if(countOne != 0){
            temp->data = 1;
            --countOne;
        }
        else{
            temp->data = 2;
            --countTwo;
        }
        temp = temp->next;
    }
}


int main(){
    Node* head = NULL;
    InsertStart(1,head);
    InsertStart(0,head);
    InsertStart(2,head);
    InsertStart(0,head);
    InsertStart(1,head);
    InsertStart(2,head); 
    InsertStart(2,head);
    InsertStart(1,head);
    InsertStart(2,head);
    InsertStart(0,head);
    InsertStart(2,head);
    InsertStart(0,head);
    InsertStart(1,head);

    cout << "Printing the Linked list: " << endl;
    printList(head);

    SortZeroOneTwo(head);

    cout << "Linked List after sorting 0, 1 & 2: " << endl;
    printList(head);
}