#include <iostream>
#include <queue>
using namespace std;

// First non-repeating character in a stream
vector<char> non_repeating(string &s)
{
    queue<char> q;
    int arr[26] = {0};
    vector<char> ans;
    for (int i = 0; i < s.size(); i++)
    {
        char ch = s[i];
        arr[ch - 'a']++;
        q.push(ch);

        while (!q.empty())
        {
            char firstChar = q.front();
            if (arr[firstChar - 'a'] > 1)
            {
                q.pop();
            }
            else
            {
                ans.push_back(firstChar);
                break;
            }
        }
        if (q.empty())
        {
            ans.push_back('#');
        }
    }
    return ans;
}

int main()
{
    string str = "abacdfiabcdz";
    vector<char> ans = non_repeating(str);
    for (auto val : ans)
    {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}