#include <iostream>
#include <vector>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode *childrens[26];
    bool isTerminal;
    TrieNode(char data)
    {
        this->data = data;
        this->isTerminal = false;
        for (int i = 0; i < 26; i++)
        {
            childrens[i] = NULL;
        }
    }
    ~TrieNode() { delete *childrens; }
};

// insert word
void insertWord(TrieNode *root, string word)
{
    // base case
    if (word.length() == 0)
    {
        root->isTerminal = true;
        return;
    }

    // one case
    char ch = word[0];
    int index = ch - 'a';
    if (root->childrens[index] != NULL)
    {
        // iska matlab persent hai
        root = root->childrens[index];
    }
    else
    {
        // matlab absent hai
        TrieNode *child = new TrieNode(ch);
        root->childrens[index] = child;
        root = child;
    }
    // recursive call
    insertWord(root, word.substr(1));
}

// get suggestion list
void srearchString(TrieNode *root, string &prefix, vector<string> &ans)
{
    // base case
    if (root->isTerminal)
    {
        ans.push_back(prefix);
    }

    for (int i = 0; i < 26; i++)
    {
        TrieNode *next = root->childrens[i];
        if (next != NULL)
        {
            prefix.push_back('a' + i);
            srearchString(next, prefix, ans);
            prefix.pop_back();
        }
    }
}
void getAllSuggestionWords(TrieNode *root, string input, vector<string> &ans,
                           string &prefix)
{
    // base case
    if (input.length() == 0)
    {
        srearchString(root, prefix, ans);
        return;
    }

    // solved one case
    char ch = input[0];
    int index = ch - 'a';
    if (root->childrens[index] != NULL)
    {
        root = root->childrens[index];
    }
    else
    {
        return;
    }

    // recursive call
    getAllSuggestionWords(root, input.substr(1), ans, prefix);
}

vector<vector<string>> suggestedProductsHelper(TrieNode *root,
                                               string searchWord)
{
    TrieNode *prev = root;
    vector<vector<string>> output;
    string tempStr = "";
    for (int i = 0; i < searchWord.length(); i++)
    {
        char ch = searchWord[i];
        TrieNode *curr = prev->childrens[ch - 'a'];
        if (curr != NULL)
        {
            tempStr.push_back(ch);
            vector<string> temp;
            srearchString(curr, tempStr, temp);
            prev = curr;
            output.push_back(temp);
        }
        else
        {
            break;
        }
    }
    return output;
}

int main()
{
    TrieNode *root = new TrieNode('-');
    insertWord(root, "love");
    insertWord(root, "lovely");
    insertWord(root, "latter");
    insertWord(root, "lover");
    insertWord(root, "loan");
    insertWord(root, "car");
    insertWord(root, "care");
    insertWord(root, "dove");
    insertWord(root, "neeraj");
    insertWord(root, "nitish");
    insertWord(root, "nitin");

    string searchWord = "love";
    vector<vector<string>> ans = suggestedProductsHelper(root, searchWord);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << i + 1 << " -> ";
        for (auto val : ans[i])
        {
            cout << val << ", ";
        }
        cout << endl;
    }

    // cout << "Enter serach word: ";
    // string input;
    // cin >> input;
    // string &prefix = input;
    // vector<string> ans;
    // getAllSuggestionWords(root, input, ans, prefix);
    // if (ans.size() == 0) {
    //   cout << "not realated words here." << endl;
    // } else {
    //   for (auto val : ans) {
    //     cout << val << " ";
    //   }
    //   cout << endl;
    // }
    // cout << prefix << endl;

    delete root;
    return 0;
}