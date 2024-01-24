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

Node* mergeInBetween(Node* list1, int a, int b, Node* list2) {
    Node* temp = list1;
    Node* previous = nullptr;
    int count = 0;
    while(count != a){
        previous = temp;
        temp = temp->next;
        count++;
    }
    while(count != b){
        temp = temp->next;
        count++;
    }
    temp = temp->next;
    previous->next = nullptr;
    previous->next = list2;
    while(previous->next != nullptr){
        previous = previous->next;
    }
    previous->next = temp;
    return list1;
}

int main(){
    Node* head1 = nullptr;
    Node* head2 = nullptr;
    InsertStart(9,head1);
    InsertStart(8,head1);
    InsertStart(7,head1);
    InsertStart(6,head1);
    InsertStart(5,head1);
    InsertStart(4,head1);
    InsertStart(3,head1);
    InsertStart(2,head1);
    InsertStart(1,head1);

    InsertStart(500,head2);
    InsertStart(400,head2);
    InsertStart(300,head2);
    InsertStart(200,head2);
    InsertStart(100,head2);
    cout << "Linked List 1: " << endl;
    printList(head1);
    cout << "Linked List 2: " << endl;
    printList(head2);
    Node* final = mergeInBetween(head1,2,4,head2);
    cout << "Linked list after merging : " << endl;
    printList(final);
}