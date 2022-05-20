#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

void solve_optimized(int n, int index, vector<int> &arr, vector<int> &ds, vector<vector<int>> &res)
{
    res.push_back(ds);
    for (int i = index; i < n; i++)
    {
        if (i != index && arr[i] == arr[i - 1])
            continue;
        ds.push_back(arr[i]);
        solve_optimized(n, i + 1, arr, ds, res);
        ds.pop_back();
    }
}

vector<vector<int>> subsetsWithDup_optimized(int n, vector<int> arr)
{
    vector<vector<int>> res;
    vector<int> ds;
    sort(arr.begin(), arr.end());
    solve_optimized(n, 0, arr, ds, res);
    return res;
}

void solve(int n, vector<int> &arr, int index, vector<int> &ds, set<vector<int>> &res)
{
    if (index == n)
    {
        sort(ds.begin(), ds.end());
        res.insert(ds);
        return;
    }
    ds.push_back(arr[index]);
    solve(n, arr, index + 1, ds, res);
    ds.pop_back();
    solve(n, arr, index + 1, ds, res);
}

vector<vector<int>> subsetsWithDup(int n, vector<int> arr)
{
    vector<vector<int>> ans;
    set<vector<int>> res;
    vector<int> ds;
    solve(n, arr, 0, ds, res);
    for (auto it = res.begin(); it != res.end(); it++)
    {
        ans.push_back(*it);
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
    vector<vector<int>> ans = subsetsWithDup(n, arr);
    cout << "[ ";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << "[ ";
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << "]";
    }
    cout << " ]";
}