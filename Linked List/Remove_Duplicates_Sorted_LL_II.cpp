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

Node* RemoveDuplicate(Node* &head){
    // Empty list or Single element in a list
    if(head == nullptr || head->next == nullptr)
        return head;
    Node* previous = nullptr;
    Node* current = head;
    Node* forward = current->next;
    while(current != nullptr && current->next != nullptr){
        int count = 1;
        while(current != nullptr && forward != nullptr && current->data == forward->data){
            ++count;
            current = current->next;
            if(current != nullptr)
                forward = current->next;
            else    
                break;
        }
        if(count > 1){
            if(previous == nullptr){
                if(current->next != nullptr){
                current = current->next;
                forward = current->next;
                head = current;
                }
                else{
                    head = nullptr;
                }
            }
            else{
                if(current->next != nullptr){
                    current = current->next;
                    previous->next = current;
                    forward = current->next;
                }
                else{
                    previous->next = nullptr;
                }
            }
        }
        else{
            if(current != nullptr){
            previous = current;
            current = current->next;
            forward = current->next;
            }
        }
    }
    return head;
}

int main(){
    Node* head = nullptr;

    InsertStart(8,head);
    InsertStart(8,head);
    InsertStart(8,head);
    InsertStart(7,head);
    InsertStart(5,head);
    InsertStart(5,head);
    InsertStart(5,head);
    InsertStart(3,head);
    InsertStart(3,head);
    InsertStart(3,head);
    InsertStart(3,head);
    InsertStart(1,head);
    InsertStart(1,head);
    InsertStart(1,head);
    InsertStart(1,head);
    InsertStart(1,head);
    InsertStart(1,head);



    cout << "Printing the linked list: " << endl;
    printList(head);
    Node* temp = RemoveDuplicate(head);
    cout << "Printing the linked list after removing duplicates: " << endl;
    printList(temp);
}