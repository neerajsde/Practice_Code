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

// REMOVE DUPLICATES IN SORTED LINKED LIST
Node* removeDuplicstes(Node* head){
    if(head == NULL){
        return head;
    }
    if(head->next == NULL){
        return head;
    }
    Node* temp = head;
    while(temp != NULL){
        if(temp->next != NULL && temp->data == temp->next->data){
            Node* nextNode = temp->next;
            temp->next = nextNode->next;
            nextNode->next = NULL;
            delete nextNode;
        }
        else{
            temp = temp->next;
        }
    }
    return head;
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;
    insert(head, tail, 10);
    insert(head, tail, 10);
    insert(head, tail, 10);
    insert(head, tail, 20);
    insert(head, tail, 20);
    insert(head, tail, 30);
    print(head);

    Node* remove_duplicate = removeDuplicstes(head);
    print(remove_duplicate);
    

    return 0;
}