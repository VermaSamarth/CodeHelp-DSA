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

Node* SortedList(Node* &head1, Node* &head2){
    if(head1 == nullptr)
        return head2;
    if(head2 == nullptr)
        return head1;

    Node* ansHead = nullptr;
    Node* ans = ansHead;
    while(head1 != nullptr && head2 != nullptr){
        if(head1->data <= head2->data){
            Node* temp = new Node(head1->data);
            if(ansHead == nullptr){
                ansHead = temp;
                ans = ansHead;
            }
            else{
                ans->next = temp;
                ans = ans->next;
            }
            head1 = head1->next;
        }
        else{
            Node* temp = new Node(head2->data);
            if(ansHead == nullptr){
                ansHead = temp;
                ans = ansHead;
            }
            else{
                ans->next = temp;
                ans = ans->next;

            }
            head2 = head2->next;
        }
    }
    while(head1 != nullptr){
        Node* temp = new Node(head1->data);
        ans->next = temp;
        ans = ans->next;
        head1 = head1->next;
    }   
    while(head2 != nullptr){
        Node* temp = new Node(head2->data);
        ans->next = temp;
        ans = ans->next;
        head2 = head2->next;
    }
    return ansHead;
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

    Node* ansHead = SortedList(head1, head2);
    printList(ansHead);

}