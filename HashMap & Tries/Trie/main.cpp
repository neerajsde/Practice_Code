#include <iostream>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;
    TrieNode(char data)
    {
        this->data = data;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
    ~TrieNode(){
        delete *children;
    }
};

// insert word
void InsertWord(TrieNode* root, string word){
    //base case
    if(word.length() == 0){
        root->isTerminal = true;
        return;
    }
    // one case slove
    char ch = word[0];
    int index = ch - 'a';
    TrieNode* child;
    if(root->children[index] != NULL){
        child = root->children[index];
    }
    else{
        child = new TrieNode(ch);
        root->children[index] = child;
    }

    // Recursive call
    InsertWord(child, word.substr(1));
}

// serach word
bool searchWord(TrieNode* root, string word){
    // base case
    if(word.length() == 0){
        return root->isTerminal;
    }
    //one case
    char ch = word[0];
    int index = ch - 'a';
    if(root->children[index] != NULL){
        root = root->children[index];
    }
    else{
        return false;
    }
    // recursive call
    return searchWord(root, word.substr(1));
}

// Delete Word
void deleteWord(TrieNode* root, string word){
    // base case
    if(word.length() == 0){
        root->isTerminal = false;
        return;
    }
    char ch = word[0];
    int index = ch - 'a';
    if(root->children[index] != NULL){
        //persent
        root = root->children[index];
    }
    else{
        // absent
        return;
    }
    // recursive call
    deleteWord(root, word.substr(1));
}

// Suggestion word

int main(){
    TrieNode* root = new TrieNode('-');
    InsertWord(root, "car"); 
    InsertWord(root, "love");
    InsertWord(root, "care");
    InsertWord(root, "dove");
    InsertWord(root, "lovely");
    InsertWord(root, "caring");
    InsertWord(root, "cuite");

    if(searchWord(root, "love")){
        cout << "Found" << endl;
    }
    else{
        cout << "Not Found" << endl;
    }

    // delete "love"
    deleteWord(root, "love");
    // Searching after delete the word
    if(searchWord(root, "love")){
        cout << "Found" << endl;
    }
    else{
        cout << "Not Found" << endl;
    }

    delete root;
    return 0;
}