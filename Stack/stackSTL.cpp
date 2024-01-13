#include<iostream>
#include<stack>
using namespace std;

// printing stack
void print(stack<int>st){
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

int main(){
    stack<int>st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    print(st);

    return 0;
} 