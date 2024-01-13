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

// REVERSE K- GROUP REVERSE
Node* ReverseKGroup(Node* head, int k){
    // Base case 
    if(head == NULL){
        return head;
    }
    if(head->next == NULL){
        return head;
    }

    // One case slove
    Node* prev = NULL;
    Node* curr = head;
    Node* next = curr->next;
    int pos = 0;
    int len = findLength(head);
    if(len < k){
        return head;
    }
    while(pos < k){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        pos++;
    }
    Node* RecusionAns = NULL;
    if(next != NULL){
        RecusionAns = ReverseKGroup(next, k);
        head->next = RecusionAns;
    }
    return prev;
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;
    for(int i=10; i<=100; i = i+10){
        insert(head, tail, i);
    }
    print(head);

    cout << "Revers K Group: " << endl;
    int k = 2; // k Group
    Node* ans = ReverseKGroup(head, k);
    print(ans);

    return 0;
}