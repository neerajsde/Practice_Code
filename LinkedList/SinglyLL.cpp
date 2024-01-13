#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(){
        this->data = 0;
        next = NULL;
    }
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
    ~Node(){}
};

// PRINTING LINKED LIST
void PrintLL(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << "-> ";
        temp = temp->next;
    }
    cout << endl;
}

// FIND LENGTH OF LINKED LIST
int lengthOfLL(Node* head){
    int count = 0;
    Node* temp = head;
    while(temp != NULL){
        ++count;
        temp = temp->next;
    }
    return count;
}

// CREATE TAIL
void createTail(Node* &head, Node* &tail){
    Node* temp = head;
    while(temp != NULL){
        temp = temp->next;
    }
    tail = temp;
}

// INSERT AT HEAD
void insertAtHead(Node* &head, Node* &tail, int data){
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else{
        // STEP 1. INSERT NEW NODE
        Node* newNode = new Node(data);
        // 2. ATTACH NEW NODE TO HEAD NODE
        newNode->next = head;
        head = newNode;
    }
}

// INSERT AT TAIL
void insertAtTail(Node* &head, Node* &tail, int data){
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else{
        // STEP 1. CREATE NEW NODE
        Node* newNode = new Node(data);
        // 2. UPDATE TAIL NEXT NODE = TEMP
        tail->next = newNode;
        // 3. UPDATE TAIL
        tail = newNode;
    }
}

// INSERT AT ANY POSITION
void insertAtPosition(Node* &head, Node* &tail, int position, int data){
    int lenght = lengthOfLL(head);
    if(position < 1 || position > lenght + 1){
        cout << "Not Vaild position to insert element." << endl;
        return;
    }
    if(position == 1){
        // THAT MEANS THEY WANT TO CHANGE FIRST ELEMENT THEN CALL INSERT AT HEAD FUNCTION...
        insertAtHead(head, tail, data);
    }
    else if(position == lenght+1){
        // THEY WANT TO INSERT AT TAIL THAT WHY CALL INSERT AT TAIL FUNSTION....
        insertAtTail(head, tail, data);
    }
    else{
        // STEP 1. CREATE A NEW NODE
        Node* newNode = new Node(data);
        // STEP 2. TRAVERSE AT TAIL
        Node* prev = NULL;
        Node* curr = head;
        while(position != 1){
            position--;
            prev = curr;
            curr = curr->next;
        }
        // STEP 3. 
        newNode->next = curr;
        // STEP 4.
        prev->next = newNode;
    }
}

// DELETE NODE FROM AT SPACEIFIED INDEX
void deleteNode(Node* &head, Node* &tail, int position){
    int len = lengthOfLL(head);
    if(head == NULL){
        cout << "Not Delete because element." << endl;
        return;
    }
    // For One element
    if(head == tail){
        Node* temp = temp;
        delete temp;
        head = NULL;
        tail = NULL;
    }
    if(position == 1){
        // For Head element
        Node* temp = head;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }
    else if(position == len){
        // For delete tail
        Node* prev = head;
        while(prev->next != tail){
            prev = prev->next;
        }
        prev->next = NULL;
        delete tail; 
        tail = prev;
    }
    else{
        // That means I want to delete into middle
        Node* prev = NULL;
        Node* curr = head;
        while(position != 1){
            position--;
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;

    insertAtTail(head, tail, 10);
    insertAtTail(head, tail, 20);
    insertAtTail(head, tail, 30);
    insertAtTail(head, tail, 40);

    PrintLL(head);
    // cout << "Len of LL: " << lengthOfLL(head) << endl;
    // insertAtPosition(head, tail, 6, 5);
    // PrintLL(head);

    deleteNode(head, tail, 3);
    PrintLL(head);

    return 0;
}