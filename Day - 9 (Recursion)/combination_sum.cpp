#include <iostream>
#include <vector>
using namespace std;

void findCombination(int n, int index, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds)
{
    if (index == n)
    {
        if (target == 0)
        {
            ans.push_back(ds);
        }
        return;
    }

    if (arr[index] <= target)
    {
        ds.push_back(arr[index]);
        findCombination(n, index, target - arr[index], arr, ans, ds);
        ds.pop_back();
    }

    findCombination(n, index + 1, target, arr, ans, ds);
}

vector<vector<int>> combinationSum(int n, vector<int> arr, int target)
{
    vector<vector<int>> ans;
    vector<int> ds;
    findCombination(n, 0, target, arr, ans, ds);
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
    vector<vector<int>> res = combinationSum(n, arr, target);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
            cout << res[i][j] << " ";
        cout << endl;
    }
}