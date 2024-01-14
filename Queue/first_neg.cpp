#include<iostream>
#include<vector>
#include<deque>
using namespace std;

// first -ve integer in very window of k
void NegativeWindow(int* arr, int n, int k){
    deque<int>q;
    for(int index=0; index<k; index++){
        if(arr[index] < 0){
            q.push_back(index);
        }
    }
    for(int index=k; index<n; index++){
        if(q.empty()){
            cout << "0 ";
        }
        else{
            cout << arr[q.front()] << " ";
        }
        if(index - q.front() >= k){
            q.pop_front();
        }
        if(arr[index] < 0){
            q.push_back(index);
        }
    }
    if(q.empty()){
        cout << "0" << endl;
    }
    else{
        cout << arr[q.front()] << endl;
    }
}

void print(int arr[], int n){
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr[] = {2, -5, 4, -1, -2, 0, 5};
    int size = sizeof(arr)/sizeof(int);
    int k = 3;
    print(arr, size);
    // first -ve integer in very window of k
    NegativeWindow(arr, size, k);
    // print(arr, size);
    return 0;
}