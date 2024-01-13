#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node() : data(0), next(NULL){}
    Node(int data) : data(data), next(NULL){}
    ~Node(){}
};

// PRINTING THE LINKED LIST
void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << "-> ";
        temp = temp->next;
    }
    cout << endl;
}

// FIND LENGTH OF LINKED LIST
int findLength(Node* head){
    Node* temp = head;
    int count = 0;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    return count;
}

// INSERT AT HEAD OR FIRST
void insert(Node* &head, Node* &tail, int data){
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else{
        Node* newNode = new Node(data);
        tail->next = newNode;
        tail = newNode;
    }
}

// REVERSE A LINKED LIST
Node* reverse(Node* head){
    Node* prev = NULL;
    Node* curr = head;
    while(curr != NULL){
        Node* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

// Add +1 TO A LINKED LIST
void AddOne(Node* &head){
    head = reverse(head);
    Node* temp = head;
    int carry = 1;
    while(temp->next != NULL){
        int data = temp->data + carry;
        int digit = data % 10;
        carry = data / 10;
        temp->data = digit;
        temp = temp->next;
        if(carry == 0){
            break;
        }
    }
    if(carry != 0){
        int totalSum = temp->data + carry;
        int digit = totalSum % 10;
        carry = totalSum / 10;
        temp->data = digit;
        if(carry != 0){
            Node* newNode = new Node(carry);
            temp->next = newNode;
        }
    }
    head = reverse(head);
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;
    insert(head, tail, 1);
    insert(head, tail, 9);
    insert(head, tail, 9);
    print(head);
    
    AddOne(head); // Add +1 into LL Data
    print(head);

    

    return 0;
}