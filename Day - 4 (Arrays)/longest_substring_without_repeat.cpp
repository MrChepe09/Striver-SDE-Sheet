#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

// O(n)
int longest_substring_optimized(int n, string s)
{
    int maxLen = 0;
    vector<int> mpp(256, -1);
    int l = 0, r = 0;
    while (r < n)
    {
        if (mpp[s[r]] != -1)
        {
            l = max(l, mpp[s[r]] + 1);
        }
        mpp[s[r]] = r;
        maxLen = max(maxLen, r - l + 1);
        r++;
    }
    return maxLen;
}

// O(2*n)
int longest_substring(int n, string s)
{
    int maxLen = 0;
    unordered_set<int> umap;
    int l = 0;
    for (int r = 0; r < n; r++)
    {
        if (umap.find(s[r]) != umap.end())
        {
            while (l < r && umap.find(s[r]) != umap.end())
            {
                umap.erase(s[l]);
                l++;
            }
        }
        umap.insert(s[r]);
        maxLen = max(maxLen, r - l + 1);
    }
    return maxLen;
}

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int len = longest_substring_optimized(n, s);
    cout << len << endl;
}