#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// Gas Stataion
int canCompleteCircuit(vector<int>&gas, vector<int>&cost){
    int dificit = 0;
    int balance = 0;
    int start = 0;

    for(int i=0; i<gas.size(); i++){
        balance = balance + gas[i] - cost[i];

        if(balance < 0){
            dificit += abs(balance);
            start = i+1;
            balance = 0;
        }
    }
    if(balance - dificit >= 0){
        return start;
    }
    return -1;
}

int main(){
    vector<int>gas = {1,2,3,4,5};
    vector<int>cost = {3,4,5,1,2};
    int indexOfGasStation = canCompleteCircuit(gas, cost);
    cout << "Index Of Gas Station: " << indexOfGasStation << endl;
    return 0;
}