#include <iostream>
#include <vector>
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
};

// insert word
void InsertWord(TrieNode *root, string word)
{
    // base case
    if (word.length() == 0)
    {
        root->isTerminal = true;
        return;
    }
    // one case slove
    char ch = word[0];
    int index = ch - 'a';
    TrieNode *child;
    if (root->children[index] != NULL)
    {
        child = root->children[index];
    }
    else
    {
        child = new TrieNode(ch);
        root->children[index] = child;
    }

    // Recursive call
    InsertWord(child, word.substr(1));
}

// serach word
bool searchWord(TrieNode *root, string word)
{
    // base case
    if (word.length() == 0)
    {
        return root->isTerminal;
    }
    // one case
    char ch = word[0];
    int index = ch - 'a';
    if (root->children[index] != NULL)
    {
        root = root->children[index];
    }
    else
    {
        return false;
    }
    // recursive call
    return searchWord(root, word.substr(1));
}

// Delete Word
void deleteWord(TrieNode *root, string word)
{
    // base case
    if (word.length() == 0)
    {
        root->isTerminal = false;
        return;
    }
    char ch = word[0];
    int index = ch - 'a';
    if (root->children[index] != NULL)
    {
        // persent
        root = root->children[index];
    }
    else
    {
        // absent
        return;
    }
    // recursive call
    deleteWord(root, word.substr(1));
}

void searchRelatedWord(TrieNode *root, string &suffix,
                       vector<string> &suggestword)
{
    if (root->isTerminal == true)
    {
        suggestword.push_back(suffix);
    }

    for (int i = 0; i < 26; i++)
    {
        TrieNode *next = root->children[i];
        if (root->children[i] != NULL)
        {
            suffix.push_back('a' + i);
            searchRelatedWord(next, suffix, suggestword);
            suffix.pop_back();
        }
    }
}
// word suggestions Algo
void findrelatedword(TrieNode *root, string input, vector<string> &suggestword,
                     string &prefix)
{
    // base case
    if (input.length() == 0)
    {
        searchRelatedWord(root, prefix, suggestword);
        return;
    }
    // one case
    char ch = input[0];
    int index = ch - 'a';
    if (root->children[index] != NULL)
    {
        root = root->children[index];
    }
    else
    {
        return;
    }
    findrelatedword(root, input.substr(1), suggestword, prefix);
}

int main()
{
    TrieNode *root = new TrieNode('-');
    InsertWord(root, "car");
    InsertWord(root, "love");
    InsertWord(root, "care");
    InsertWord(root, "dove");
    InsertWord(root, "lovely");
    InsertWord(root, "caring");
    InsertWord(root, "cuite");
    InsertWord(root, "neeraj");
    InsertWord(root, "nitin");
    InsertWord(root, "nitish");

    cout << "Enter Search related word: ";
    string input; cin>>input;
    string &prefix = input;
    vector<string> suggestword;
    findrelatedword(root, input, suggestword, prefix);

    if (suggestword.size() == 0)
    {
        cout << "Not Exist any word." << endl;
    }
    else
    {
        for (auto i : suggestword)
        {
            cout << i << " ";
        }
    }
    cout << endl;

    return 0;
}