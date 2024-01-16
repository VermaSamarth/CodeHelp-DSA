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

int findLength(Node* &head){
    Node* temp = head;
    int count = 0;
    while(temp != NULL){
        temp = temp->next;
        count++;
    }
    return count;
}

Node* DeleteNode(Node* &head, int &position){
    if(head == NULL)
        return NULL;
    Node* curr = head;
    if(position == 0){
        Node* prev = curr;
        curr = curr->next;
        head = curr;
        prev->next = NULL;
        delete prev;
        cout << "Deleted the node.." << endl;
        return curr;
    }
    else{
        int count = 0;
        while(count < position){
            curr = curr->next;
            count++;
        }
        if(curr->next->next == NULL){
            curr->next = NULL;
        }
        else{
            Node* prev = curr->next;
            curr->next = curr->next->next;
            prev->next = NULL;
            delete prev;
        }
        cout << "Deleted the node.." << endl;
        return curr;
    }
}

Node* RemoveElement(Node* &head, int value){
    if(head == NULL)
        return NULL;
    int position = 0;
    Node* temp = head;
    while(temp != NULL){
        if(temp->data == value){
            cout << "Deleting the node.." << endl;
            temp = DeleteNode(head,position);
            cout << temp->data << endl;
            temp = temp->next;
        }
        else{
            position++;
            cout << temp->data << endl;
            temp = temp->next;
        }
        
    }
    return head;
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
    InsertStart(50,head);
    InsertStart(30,head);
    InsertStart(10,head);
    head = RemoveElement(head,30);
    printList(head);
}