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

// Find Length function
int findLength(Node* &head){
    Node* temp = head;
    int count = 0;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    return count;
}

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

// Function to detect loops
bool Detect_Loops(Node* &head){
    if(head == NULL){
        cout << "Linked List is empty..." << endl;
        return false;
    }

    Node* slow = head;
    Node* fast = head;
    while(fast != NULL && slow != NULL){
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
            slow = slow->next;
        }

        if(fast == slow){
            return true;
        }
    }
    return NULL;
}

Node* Detect_Loop_Position(Node* &head){
    if(head == NULL){
        cout << "Linked List is empty..." << endl;
        return NULL;
    }

    Node* slow = head;
    Node* fast = head;
    while(fast != NULL && slow != NULL){
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
            slow = slow->next;
        }

        if(fast == slow){
            slow = head;
            break;
        }
    }
    Node* previous = fast;
    while(slow != fast){
        previous = fast;
        fast = fast->next;
        slow = slow->next;
    }
    previous->next = NULL;
    return slow;
}

int main(){
    Node* head = NULL;
    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);
    Node* fifth = new Node(50);
    Node* sixth = new Node(60);
    Node* seventh = new Node(70);
    Node* eigth = new Node(80);
    Node* nineth = new Node(90);

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
    seventh->next = eigth;
    eigth->next = nineth;
    nineth->next = fifth;
    
    head = first;

    if(Detect_Loops(head)){
        cout << "Loops detected...." << endl;
        cout << "Loop starts at the node: " << Detect_Loop_Position(head)->data << endl;
    }
    else    
        cout << "Loop not detected....." << endl;

    

    if(Detect_Loops(head))
        cout << "Loops not removed successfully....." << endl;
    else{
        cout << "Loop removed successfully...Nothing detected....." << endl;
        cout << "Linked List: " << endl;
        printList(head);
    }    
    
}