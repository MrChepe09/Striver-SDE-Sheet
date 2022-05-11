#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// O(n)
vector<int> two_sum_optimized(int n, vector<int> arr, int target)
{
    vector<int> ans;
    unordered_map<int, int> umap;
    for (int i = 0; i < n; i++)
    {
        if (umap.find(target - arr[i]) != umap.end())
        {
            ans.emplace_back(i);
            ans.emplace_back(umap[target - arr[i]]);
            return ans;
        }
        umap[arr[i]] = i;
    }
    return ans;
}

// O(nlogn)
vector<int> two_sum(int n, vector<int> arr, int target)
{
    vector<int> ans;
    int start = 0, end = n - 1;
    while (start < end)
    {
        if (arr[start] + arr[end] == target)
        {
            ans.emplace_back(start);
            ans.emplace_back(end);
            return ans;
        }
        else if (arr[start] + arr[end] > target)
        {
            end--;
        }
        else
        {
            start++;
        }
    }
    return ans;
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
    int target;
    cin >> target;
    vector<int> ans = two_sum(n, arr, target);
    cout << ans[0] << " " << ans[1] << endl;
}