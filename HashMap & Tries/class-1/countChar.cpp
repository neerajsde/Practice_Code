#include<iostream>
#include<unordered_map>
using namespace std;

// Count Char Frequency
void countCharFrequency(unordered_map<char,int>&map, string&str){
    for(auto ch: str){
        map[ch]++;
    }
}

int main(){
    string str = "Neeraj_Prajapati";
    unordered_map<char, int>map;
    countCharFrequency(map, str);

    // Printing Frequnecy
    for(auto val: map){
        cout << val.first << " -> " <<  val.second << endl;
    }
    
    return 0;
}