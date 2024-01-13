#include<iostream>
using namespace std;

class Stack{
private:
    int *arr;
    int size;
    int top;
public:
    Stack(int size){
        this->arr = new int[size];
        this->size = size;
        this->top = -1;
    }
    void push(int data){
        if(top+1 == size){
            cout << "Stack overflow" << endl;
        }
        else{
            top++;
            arr[top] = data;
        }
    }
    void pop(){
        if(top == -1){
            cout << "Stack underflow" << endl;
        }
        else{
            top--;
        }
    }
    int Top(){
        if(top == -1){
            return -1;
        }
        return arr[top];
    }
    bool isEmpty(){
        if(top == -1){
            return true;
        }
        else{
            return false;
        }
    }
    int getSize(){
        return top + 1;
    }
};

// printing stack
void print(Stack &st){
    if(st.isEmpty()) return;
    int temp = st.Top();
    st.pop();
    print(st);
    cout << temp << " ";
    st.push(temp);
}

void slove(Stack &st, int &mid, int &ans){
    // base case
    if(mid == 1){
        ans = st.Top();
        return;
    }
    mid--;
    int temp = st.Top();
    st.pop();
    //recusion
    slove(st, mid, ans);
    // backtrack
    st.push(temp);
}

// Middle element of a Stack
int getMiddleElement(Stack st){
    int mid;
    if(st.getSize() & 1){
        // Odd 
        mid = st.getSize() / 2 + 1;
    }
    else{
        // Even
        mid = st.getSize() / 2;
    }
    int ans = -1;
    slove(st, mid, ans);
    return ans;
}

// INSERT AT BOTTOM OF STACK
void insertAtBottom(Stack &st, int &data){
    if(st.isEmpty()){
        st.push(data);
        return;
    }
    // 1 case
    int temp = st.Top();
    st.pop();
    // recursive
    insertAtBottom(st, data);
    // backtrack
    st.push(temp);
}

// Reverse a Stack
void Reverse(Stack &st){
    if(st.isEmpty()) return;

    // one case
    int temp = st.Top();
    st.pop();
    // recursive
    Reverse(st);
    // backtracking
    insertAtBottom(st, temp);
}

int main(){
    Stack st(10);
    for(int i=10; i<=100; i=i+10){
        st.push(i);
    }
    print(st);
    cout << endl;
    // cout << "\nMid element is: " << getMiddleElement(st) << endl;
    // int data = 20;
    // insertAtBottom(st, data);
    Reverse(st);
    print(st); cout << endl;
    Reverse(st);
    print(st);
    return 0;
}