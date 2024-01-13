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

// REVERSE THE LINKED LIST 1. Approach
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

// 2. Approach to reverse the LL
Node* reverse2Helper(Node* prev, Node* curr){
    if(curr == NULL){
        return prev;
    }
    Node* nextNode = curr->next;
    curr->next = prev;
    prev = curr;
    curr = nextNode;
    return reverse2Helper(prev, curr);
}
Node* reverse2(Node* head){
    Node* prev = NULL;
    Node* curr = head;
    return reverse2Helper(prev, curr);
}

// MIDDLE OF A LINKED LIST - THIS IS SLOW FAST APPROACH
Node* middleNode(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL){
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
            slow = slow->next;
        }
    }
    return slow;
}

// CHECK FOR LOOP IN LINKED LIST - LINKED LIST CYCLE
bool isLoopedLL(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL){
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
            slow = slow->next;
        }
        else{
            break;
        }
        if(fast == slow){
            return true;
            break;
        }
    }
    return false;
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;
    insert(head, tail, 10);
    insert(head, tail, 20);
    insert(head, tail, 30);
    insert(head, tail, 40);
    insert(head, tail, 50);
    insert(head, tail, 60);
    print(head);

    tail->next = head->next->next;
    if(isLoopedLL(head)){
        cout << "It is for loop linked list." << endl;
    }
    else{
        cout << "It is not loop linked list." << endl;
    }

    return 0;
}