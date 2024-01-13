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

Node* SortZeroOneTwo(Node* &head){
    if(head == NULL){
        cout << "List is empty...." << endl;
        return NULL;
    }
    if(head->next == NULL){
        cout << "Already sorted as only 1 node present...." << endl;
        return head;
    }

    // Dummy Nodes
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;

    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;

    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;

    Node* current = head;
    while(current != NULL){
        Node* temp = current;
        
        if(current->data == 0){
            zeroTail->next = temp;
            zeroTail = temp;
        } 
       else if(current->data == 1){
            oneTail->next = temp;
            oneTail = temp;
        } 
        else{
            twoTail->next = temp;
            twoTail = temp;
        }
        current = current->next;
        temp->next = NULL;
    }
    
    printList(zeroHead);
    printList(oneHead);
    printList(twoHead);

    // Modify the dummy nodes of the dummy lists
    Node* temp = oneHead;
    oneHead = oneHead->next;
    temp->next = NULL;
    delete temp;

    temp = twoHead;
    twoHead = twoHead->next;
    temp->next = NULL;
    delete temp;

    if(oneHead != NULL){
        zeroTail->next = oneHead;
        if(twoHead != NULL)
            oneTail->next = twoHead;
    }
    else{
        if(twoHead != NULL){
            zeroTail->next = twoHead;
        }
    }

    temp = zeroHead;
    zeroHead = zeroHead->next;
    temp->next = NULL;
    delete temp;

    return zeroHead;
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

    head = SortZeroOneTwo(head);

    cout << "Linked List after sorting 0, 1 & 2: " << endl;
    printList(head);
}