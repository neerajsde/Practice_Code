#include<iostream>
using namespace std;

// DOUBLY LINKED LIST
class Node{
public:
    int data;
    Node* prev;
    Node* next;
    Node(){
        this->data = 0;
        this->prev = NULL;
        this->next = NULL;
    }
    Node(int data){
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
    ~Node(){}
};

// PRINTING DOUBLY LINKED LIST
void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << "-> ";
        temp = temp->next;
    }
    cout << endl;
}

// FIND LENGTH OF LINKED LIST OR NODE
int findLength(Node* head){
    Node* temp = head;
    int count = 0;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    return count;
}

// INSERT AT HEAD
void insertAtHead(Node* &head, Node* &tail, int data){
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else{
        Node* newNode = new Node(data);
        head->prev = newNode;
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
        Node* newNode = new Node(data);
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

// INSERT AT POSITION
void insertAtPosition(Node* &head, Node* &tail, int position, int data){
    int len = findLength(head);
    if(position == 1){
        // INSERT AT HEAD OR FIRST
        insertAtHead(head, tail, data);
    }
    else if(position == len + 1){
        //  INSERT AT TAIL OR END
        insertAtTail(head, tail, data);
    }
    else{
        // THAT MEANS INSERT TO MIDDLE
        Node* newNode = new Node(data);
        Node* prevNode = NULL;
        Node* currNode = head;
        while(position != 1){
            position--;
            prevNode = currNode;
            currNode = currNode->next;
        }
        prevNode->next = newNode;
        newNode->prev = prevNode;
        newNode->next = currNode;
        currNode->prev = newNode;
    }
}

// DELETE NODE AT POSITION
void deleteNode(Node* &head, Node* &tail, int position){
    // Single Node
    if(head == tail){
        Node* temp = head;
        delete temp;
        head = NULL;
        tail = NULL;
        return;
    }
    int len = findLength(head);
    if(position == 1){
        // DELETE FROM HEAD
        Node* temp = head;
        head = temp->next;
        temp->next = NULL;
        head->prev = NULL;
        delete temp;
    }
    else if(position == len){
        // DELETE FROM TAIL OR END
        Node* temp = tail;
        tail = temp->prev;
        tail->next = NULL;
        temp->prev = NULL;
        delete temp;
    }
    else{
        // DELETE FROM MIDDLLE
        Node* prevNode = NULL;
        Node* currNode = head;
        while(position != 1){
            position--;
            prevNode = currNode;
            currNode = currNode->next;
        }
        Node* currNextNode = currNode->next;
        prevNode->next = currNextNode;
        currNode->next = NULL;
        currNode->prev = NULL;
        currNextNode->prev = prevNode;
        delete currNode;
    }
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;

    // insertAtHead(head, tail, 50);
    insertAtTail(head, tail, 10);
    insertAtTail(head, tail, 20);
    insertAtTail(head, tail, 30);
    insertAtTail(head, tail, 40);
    insertAtTail(head, tail, 50);

    print(head);
    // cout << "Length of LL " << findLength(head) << endl;

    // insertAtPosition(head, tail, 4, 1000);
    // print(head);

    deleteNode(head, tail, 1);
    deleteNode(head, tail, 1);
    // deleteNode(head, tail, 1);
    deleteNode(head, tail, 1);
    deleteNode(head, tail, 1);
    print(head);

    insertAtTail(head, tail, 5);
    insertAtHead(head, tail, 20);
    insertAtTail(head, tail, 10);
    insertAtPosition(head, tail, 1, 8);
    insertAtPosition(head, tail, 6, 80);
    print(head);

    return 0;
}