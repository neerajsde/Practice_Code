#include<iostream>
#include<queue>
using namespace std;

int main(){
    queue<int>q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);

    cout << "Fron: " << q.front() << endl;
    cout << "Back: " << q.back() << endl;

    q.pop();
    
    cout << "Size: " << q.size() << endl;
    cout << "Empty: " << q.empty() << endl;

    q.pop();
    q.pop();
    q.pop();
    cout << "Empty: " << q.empty() << endl;

    return 0;
}