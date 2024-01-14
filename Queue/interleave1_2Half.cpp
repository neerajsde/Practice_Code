#include<iostream>
#include<stack>
#include<queue>
using namespace std;

// Interleave first and second half of Queue
void InterLeave(queue<int>&first){
    int n = first.size();
    queue<int>second;
    for(int i=0; i<n/2; i++){
        second.push(first.front());
        first.pop();
    }
    for(int i=0; i<n/2; i++){
        first.push(second.front());
        second.pop();
        first.push(first.front());
        first.pop();
    }
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
    for(int i=10; i<=80; i=i+10){
        q.push(i);
    }
    cout << "Print: " << endl;
    print(q);
    cout << "Interleave first & second half of Queue: " << endl;
    InterLeave(q);
    print(q);
    return 0;
}