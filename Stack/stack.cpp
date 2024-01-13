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

int main(){
    Stack st(20);
    for(int i=10; i<=200; i=i+10){
        st.push(i);
    }
    print(st); cout << endl;
    // for(int i=0; i<=21; i++){
    //     st.pop();
    // }
    if(st.isEmpty()){
        cout << "Empty Stack" << endl;
    }
    else{
        cout << "Non empty stack" << endl;
    }
    // print(st); cout << endl;
    cout << st.Top() << endl;
    st.pop();
    st.pop();
    st.pop();
    cout << st.getSize() << endl;

    return 0;
}