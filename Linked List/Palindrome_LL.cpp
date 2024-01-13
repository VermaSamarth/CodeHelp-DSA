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

Node* reverseFromMid(Node* &head){
    Node* previous = NULL;
    Node* current = head;
    Node* forward = current->next;
    while(current != NULL){
        forward = current->next;
        current->next = previous;
        previous = current;
        current = forward;
    }
    return previous;
}

bool checkPalindrome(Node* &head){
    if(head == NULL){
        cout << "Linked list is empty..." << endl;
        return false;
    }
    if(head->next == NULL){
        return true;
    }
    
    Node* slow = head;
    Node* fast = head->next;
    while(fast != NULL){
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
            slow = slow->next;
        }
    }

    Node* forward = slow->next;
    Node* temp1 = head;
    Node* temp2 = reverseFromMid(forward);
    slow->next = temp2;
    while(temp1->data == temp2->data){
        temp1 = temp1->next;
        temp2 = temp2->next;
        if(temp2 == NULL)
            return true;
    }
    return false;
}

int main(){
    Node* head = NULL;
    InsertStart(10,head);
    InsertStart(30,head);
    InsertStart(50,head); 
    // InsertStart(70,head);
    InsertStart(70,head);
    InsertStart(50,head);
    InsertStart(30,head);
    InsertStart(10,head);

    cout << "Printing the Linked list: " << endl;
    printList(head);
    
    bool isPalindrome = checkPalindrome(head);
    if(isPalindrome)
        cout << "Linked List is a palindrome...." << endl;
    else    
        cout << "Linked List is not a palindrom...." << endl;
}