#include<iostream>
using namespace std;

// CREATE TWO STACK INTO ONE STACK
class Stack{
    public:
        int* arr;
        int size;
        int top1;
        int top2;
    public:
        Stack(int size){
            this->arr = new int[size];
            this->top1 = -1;
            this->top2 = size;
            this->size = size;
        }
        ~Stack(){}

        void push1(int data){
            if(top2 - top1 == 1){
                cout << "Stack OVERFLOW" << endl;
            }
            else{
                top1++;
                arr[top1] = data;
            }
        }
        void push2(int data){
            if(top2 - top1 == 1){
                cout << "Stack OVERFLOW" << endl;
            }
            else{
                top2--;
                arr[top2] = data;
            }
        }
        void pop1(){
            if(top1 == -1){
                cout << "Stack UNDERFLOW" << endl;
            }
            else{
                arr[top1] = 0;
                top1--;
            }
        }
        void pop2(){
            if(top2 == size){
                cout << "Stack UNDERFLOW" << endl;
            }
            else{
                arr[top2] = 0;
                top2++;
            }
        }
        int Top1(){
            if(top1 == -1){
                return -1;
            }
            else{
                return arr[top1];
            }
        }
        int Top2(){
            if(top2 == size){
                return -1;
            }
            else{
                return arr[top2];
            }
        }
        bool isEmpty1(){
            if(top1 == -1){
                return true;
            }
            else{
                return false;
            }
        }
        bool isEmpty2(){
            if(top2 == size){
                return true;
            }
            else{
                return false;
            }
        }
        // print method for check
        void print(){
            cout << endl;
            cout << "Top1: " << top1 << endl;
            cout << "Top2: " << top2 << endl;
            for(int i=0; i<size; i++){
                cout << arr[i] << " ";
            }
            cout << endl;
        }
};

int main(){
    Stack st(10);
    st.push1(1);
    st.push1(2);
    st.push1(3);
    st.print();

    st.push2(20);
    st.print();
    st.push1(4);
    st.push2(80);
    st.print();
    st.push1(1000);
    st.push2(10);
    st.print();
    st.pop1();  
    st.pop1();
    st.pop1();
    st.pop1();

    st.pop2();
    st.print();
    cout << "st1->Top: " << st.Top1() << endl;  
    cout << "st2->Top: " << st.Top2() << endl;
    st.pop1();
    st.pop1();

    return 0;
}