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
    Node* head1 = NULL;
    Node* head2 = NULL;
    
    InsertStart(8,head1);
    InsertStart(7,head1);
    InsertStart(5,head1);
    InsertStart(3,head1);
    InsertStart(1,head1);

    InsertStart(6,head2);
    InsertStart(5,head2);
    InsertStart(4,head2);
    InsertStart(2,head2);
    InsertStart(1,head2);

    printList(head1);
    printList(head2);

}