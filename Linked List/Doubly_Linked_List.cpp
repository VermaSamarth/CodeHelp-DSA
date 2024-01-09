#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* previous;
        Node(int data){
            this->data = data;
            this->next = NULL;
            this->previous = NULL;
        }
        ~Node(){
            cout << "Node is deleted...." << endl;
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
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    Node* newNode = new Node(data);
    newNode->next = head;
    head->previous = newNode;
    head = newNode;
    return;
}

void InsertEnd(int data, Node* &head, Node* &tail){
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    Node* newNode = new Node(data);
    tail->next = newNode;
    newNode->previous = tail;
    tail = newNode;
    return;
}

void InsertPosition(int data, int position, Node* &head, Node* &tail){
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

    int pos = 0;
    Node* left = head;
    while(pos < position){
        left = left->next;
        ++pos;
    }
    Node* right = left->next;
    Node* newNode = new Node(data);
    newNode->next = right;
    right->previous = newNode;
    left->next = newNode;
    newNode->previous = left;
    return;
}

void deleteNode(int position, Node* &head, Node* &tail){
    if(head == NULL){
        cout << "List is empty. Can't delete....." << endl;
        return; 
    }
    if(head->next == NULL){
        delete head;
        return;
    }
    
    if(position == 0){
        Node* temp = head;
        head = head->next;
        head->previous = NULL;
        temp->next = NULL;
        delete temp;
        return;
    }

    int len = findLength(head);
    if(position == len - 1){
        Node* temp = tail;
        tail = tail->previous;
        tail->next = NULL;
        temp->previous = NULL;
        delete temp;
        return;
    }

    int pos = 1;
    Node* curr = head;
    while(pos < position){
        curr = curr->next;
        pos++;
    }
    Node* left = curr->previous;
    Node* right = curr->next;
    left->next = right;
    right->previous = left;
    curr->previous = NULL;
    curr->next = NULL;
    delete curr;
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
    Node* tail = NULL;
    InsertStart(41,head,tail);
    InsertStart(31,head,tail);
    InsertStart(20,head,tail);
    InsertStart(11,head,tail);
    InsertPosition(50,4,head,tail);
    InsertPosition(60,5,head,tail);
    InsertEnd(74,head,tail);
    InsertEnd(80,head,tail);
    InsertEnd(90,head,tail);
    InsertEnd(100,head,tail);

    cout << "Printing the list: " << endl;
    printList(head);

    deleteNode(5,head,tail);
    cout << "After Deletion...." << endl;
    cout << "Printing the list: " << endl;
    printList(head);
}