#include<iostream>
#include<stack>
using namespace std;

// REMOVE REDUNDANT BRACKETS
bool CheckRedundantBracket(string s){
    stack<char> st;
    int operatorCount = 0;
    for(char ch: s){
        if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/'){
            st.push(ch);
        }
        else if(ch == ')'){
            while(!st.empty() && st.top() != '('){
                char temp = st.top();
                if(temp == '+' || temp == '-' || temp == '*' || temp == '/'){
                    operatorCount++;
                }
                st.pop();
            }
            st.pop();
            if(operatorCount == 0){
                return true;
            }
        }
    }
    return false;
}

int main(){
    string s = "((a)+(a+b))";
    bool ans = CheckRedundantBracket(s);
    if(ans){
        cout << "Redundant Bracket Present" << endl;
    }
    else{
        cout << "Redundant Bracket Not Present" << endl;
    }
    return 0;
}