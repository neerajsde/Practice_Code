#include<iostream>
#include<unordered_map>
using namespace std;

// CONVERT ROMAN TO INTEGER
int RomanToInt(string s){
    unordered_map<char, int>roman = {{'I', 1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
    int total = 0;
    int prev_val = 0;
    for(char ch: s){
        int curr_val = roman[ch];
        if(curr_val > prev_val){
            total += curr_val - 2 * prev_val;
        }
        else{
            total += curr_val;
        }
        prev_val = curr_val;
    }
    return total;
}
int main(){
    string s; cout << "Enter Roman number: "; cin >> s;
    int ans = RomanToInt(s);
    cout << "Number is: " << ans << endl;
    return 0;
}