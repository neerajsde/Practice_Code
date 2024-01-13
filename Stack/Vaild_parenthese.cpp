#include<iostream>
#include<stack>
using namespace std;

// CHECK VAILD PARENTHESES
bool isValid(string s){
    stack<char>st;
    for(char ch: s){
        if(ch == '(' || ch == '{' || ch == '['){
            st.push(ch);
        }
        else{
            if(!st.empty()){
                if(ch == ')' && st.top() == '('){
                    st.pop();
                }
                else if(ch == '}' && st.top() == '{'){
                    st.pop();
                }
                else if(ch == ']' && st.top() == '['){
                    st.pop();
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
    }
    if(st.empty()){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    string s = "({[()]})";
    bool ans = isValid(s);
    if(ans){
        cout << "Vaild Parentheses" << endl;
    }
    else{
        cout << "Unvalid Parentheses" << endl;
    }
    return 0;
}