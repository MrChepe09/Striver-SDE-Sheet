#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isPallindrome(string s, int start, int end)
{
    while (start <= end)
    {
        if (s[start++] != s[end--])
        {
            return false;
        }
    }
    return true;
}

void solve(int n, int index, string &s, vector<vector<string>> &res, vector<string> &path)
{
    if (index == n)
    {
        res.push_back(path);
        return;
    }

    for (int i = index; i < n; i++)
    {
        if (isPallindrome(s, index, i))
        {
            path.push_back(s.substr(index, i - index + 1));
            solve(n, i + 1, s, res, path);
            path.pop_back();
        }
    }
}

vector<vector<string>> partition(int n, string &s)
{
    vector<vector<string>> res;
    vector<string> path;
    solve(n, 0, s, res, path);
    return res;
}

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<vector<string>> res = partition(n, s);
    cout << " [ ";
    for (auto i : res)
    {
        cout << "[ ";
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << "] ";
    }
    cout << "]";
}