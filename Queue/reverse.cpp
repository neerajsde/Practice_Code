#include<iostream>
#include<queue>
#include<stack>
using namespace std;

// Rverse a Queue Approach 1. use stack
void reverseQue(queue<int>&q){
    stack<int>st;
    while(!q.empty()){
        st.push(q.front());
        q.pop();
    }
    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }
}
// 2. Approach using recursion
void reverse(queue<int>&q){
    if(q.empty()){
        return;
    }
    int temp = q.front();
    q.pop();

    // recusive call
    reverse(q);

    // backtracking
    q.push(temp);
}
void print(queue<int>q){
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}
int main(){
    queue<int>q;
    for(int i=10; i<=100; i=i+10){
        q.push(i);
    }
    // printing
    cout << "Print: " << endl;
    print(q);
    // reverse
    reverseQue(q);
    // reverse(q);
    cout << "Reversed Queue" << endl;
    print(q);
    return 0;
}