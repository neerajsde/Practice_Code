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

// INSERT SORTED
void inserSorted(Stack &st, int element){
    // base case 
    if(st.isEmpty() || element > st.Top()){
        st.push(element);
        return;
    }
    // one case
    int temp = st.Top();
    st.pop();
    // recursive
    inserSorted(st, element);
    // backtracking
    st.push(temp);
}

void sortStack(Stack &st){
    // base case
    if(st.isEmpty()){
        return;
    }
    int temp = st.Top();
    st.pop();
    // recursive
    sortStack(st);
    // beacktracking
    inserSorted(st, temp);
}

int main(){
    // int size = 20;
    // Stack st(size);
    // for(int i=0; i<=size*4; i=i+5){
    //     st.push(i);
    // }
    // print(st); cout << endl;
    // inserSorted(st, 32);
    // print(st);
    
    int arr[] = {20,8,10,5,6,1,8,9,11,18};
    int size = sizeof(arr)/sizeof(int);
    Stack st(size);
    for(int i=0; i<size; i++){
        st.push(arr[i]);
    }
    print(st); cout << endl;
    cout << "Sorted Stack" << endl;
    sortStack(st);
    print(st);
    return 0;
}