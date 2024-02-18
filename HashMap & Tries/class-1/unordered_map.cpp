#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    // Creation
    unordered_map<string, int>mapping;

    // Insertion
    pair<string, int>p = make_pair("Love", 20);

    pair<string, int>q("Neeraj", 85);

    // Insert into map
    mapping.insert(p);
    mapping.insert(q);

    // size of map
    cout << "Size of Map: " << mapping.size() << endl;

    // Again insert
    mapping["Vijay"] = 10;
    cout << "Size of Map: " << mapping.size() << endl;

    // Acess
    cout << mapping["Neeraj"] << endl;
    cout << mapping["Love"] << endl;
    cout << mapping["Vijay"] << endl;
    // Or
    cout << mapping.at("Neeraj") << endl;

    // Searching 
    cout << mapping.count("Love") << endl; // if return 1 means present else 0 means not persent

    // Searching another Way
    if(mapping.find("Neeraj") != mapping.end()){
        cout << "Found" << endl;
    }
    else{
        cout << "Not Found" << endl;
    }
    return 0;
}