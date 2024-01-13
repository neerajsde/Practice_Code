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

Node* addTwoNumbers(Node* l1, Node* l2) {
    Node* ans = new Node(-1);
    Node* it = ans;
    int carry = 0;
    while(l1 || l2 || carry){
        int l1_val = l1 ? l1->data : 0;
        int l2_val = l2 ? l2->data : 0;
        int sum = l1_val + l2_val + carry;
        int digit = sum % 10;
        carry = sum / 10;
        Node* newNode = new Node(digit);
        it->next = newNode;
        it = newNode;
        l1 = l1 ? l1->next : NULL;
        l2 = l2 ? l2->next : NULL;
    }
    Node* temp = ans;
    ans = ans->next;
    delete temp;
    return ans;
}


int main(){
    Node* l1_head = NULL;
    Node* l1_tail = NULL;
    insert(l1_head, l1_tail, 2);
    insert(l1_head, l1_tail, 4);
    insert(l1_head, l1_tail, 3);
    print(l1_head);

    Node* l2_head = NULL;
    Node* l2_tail = NULL;
    insert(l2_head, l2_tail, 5);
    insert(l2_head, l2_tail, 6);
    insert(l2_head, l2_tail, 4);
    print(l2_head);

    Node* ans = addTwoNumbers(l1_head, l2_head); // Add two number
    print(ans);

    return 0;

}