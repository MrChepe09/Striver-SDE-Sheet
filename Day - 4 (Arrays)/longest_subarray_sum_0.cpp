#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int longest_subarray_zero(int n, vector<int> arr)
{
    int maxLen = 0;
    unordered_map<int, int> umap;
    int prefix_sum = 0;
    for (int i = 0; i < n; i++)
    {
        prefix_sum += arr[i];
        if (prefix_sum == 0)
        {
            maxLen = i + 1;
        }
        else
        {
            if (umap.find(prefix_sum) != umap.end())
            {
                maxLen = max(maxLen, i - umap[prefix_sum]);
            }
            else
            {
                umap[prefix_sum] = i;
            }
        }
    }
    return maxLen;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int len = longest_subarray_zero(n, arr);
    cout << len << endl;
}