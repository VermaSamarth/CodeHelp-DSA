#include<iostream>
using namespace std;

// Creating the class node and store two data members: data and object "next"
class Node{
    public:
        int data;
        Node* next;

        // Parameterized Constructor to initialize the data members
        Node(int data){
            this->data = data;
            this->next = NULL;
        }

        // Destructor to delete the node
        ~Node(){
            cout << "Node has been deleted." << endl;
        }
};

// Function to find the length of the linked list
int findLength(Node* &head){
    int count = 0;
    Node* temp = head;
    while(temp != NULL){
        temp = temp->next;
        ++count;
    }
    return count;
}

// Function to add the node at the beginning of the linked list
void InsertFront(int data, Node* &head, Node* &tail){
    // If the linked list is empty
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    // If the linked list is not empty
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

// Function to insert the node at the end of the linked list
void InsertEnd(int data, Node* &head, Node* &tail){
    // If the linked list is empty
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    // If the linked list is not empty
    Node* newNode = new Node(data);
    tail->next = newNode;
    tail = newNode;
}

// Function to add the linked list at a position.
void InsertPosition(int data, int position, Node* &head, Node* &tail){
    // If the linked list is empty.
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    // If the position is 0;
    if(position == 0){
        InsertFront(data,head,tail);
        return;
    }

    // If the position is at the end of the linked list
    int len = findLength(head);
    if(position >= len){
        InsertEnd(data,head,tail);
        return;
    }

    //Insert in the inside positions
    Node* previous = head;
    int pos = 1;
    // Reaching the position where the node is to inserted.
    while(pos != position){
        previous = previous->next;
        ++pos;
    }
    Node* current = previous->next;
    Node* newNode = new Node(data);
    newNode->next = current;
    previous->next = newNode;
}

// Deletion in the Linked List From any position
void DeleteNode(int position, Node* &head, Node* &tail){
    // If the linked list is empty.
    if(head == NULL){
        cout << "Linked List is empty. Can't delete the node." << endl;
        return;
    }

    // If the particular is not present.
    int len = findLength(head);
    if(position > len){
        cout << "Node can't be deleted. Node not present at the position." << endl; 
        return;
    }
    
    // If the position is at the beginning of the list
    if(position == 0){
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        return;
    }

    // If the position is the end of the list
    if(len == position){
        Node* previous = head;
        while(previous->next != tail){
            previous = previous->next;
        }
        Node* temp = tail;
        previous->next = NULL;
        tail = previous;
        temp->next = NULL;
        delete temp; 
        return;
    }

    // Delete a node from the middle of the list
    int pos = 1;
    Node* previous = head;
    while(pos < position){
        previous = previous->next;
        ++pos;
    }
    Node* temp = previous->next;
    previous->next = temp->next;
    temp->next = NULL;
    delete temp;
}

void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;

    InsertEnd(100,head,tail);
    InsertEnd(200,head,tail);
    InsertEnd(300,head,tail);
    InsertEnd(400,head,tail);
    cout << "Printing the Linked List (End Insertion): " << endl;
    print(head);
    cout << endl;

    InsertFront(20,head,tail);
    InsertFront(40,head,tail);
    InsertFront(60,head,tail);
    InsertFront(80,head,tail);
    cout << "Printing the Linked List (Front Insertion): " << endl;
    print(head);
    cout << endl;

    InsertPosition(250,6,head,tail);
    InsertPosition(450,9,head,tail);
    InsertPosition(10,0,head,tail);
    InsertPosition(250,15,head,tail);
    cout << "Printing the Linked List (Middle Insertion): " << endl;
    print(head);
    cout << endl;

    DeleteNode(0,head,tail);
    DeleteNode(2,head,tail);
    DeleteNode(20,head,tail);
    cout << "Printing the Linked List (After Deletion): " << endl;
    print(head);
    cout << endl;
}