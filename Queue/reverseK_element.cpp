#include<iostream>
#include<queue>
#include<stack>
using namespace std;

// REVERSE K ELEMENT
void revKelement(queue<int>&q, int k){
    int n = q.size();
    if(n < k || n == 0) return;
    stack<int>st;
    // push first k element queue to stack
    for(int i=0; i<k; i++){
        st.push(q.front());
        q.pop();
    }
    // push all k element from stack to queue
    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }
    // shift n-k element from last queue
    for(int i=0; i<(n-k); i++){
        int temp = q.front();
        q.pop();
        q.push(temp);
    }
}
// printing
void print(queue<int>q){
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main(){
    queue<int>q;
    for(int i=10; i<100; i=i+10){
        q.push(i);
    }
    print(q);
    int k = 4;
    revKelement(q, k);
    cout << "Reverse K element: " << endl;
    print(q);
    return 0;
}