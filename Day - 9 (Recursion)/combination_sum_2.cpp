#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void findCombination(int n, int index, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds)
{
    if (target == 0)
    {
        ans.push_back(ds);
        return;
    }

    for (int i = index; i < n; i++)
    {
        if (i > index && arr[i] == arr[i - 1])
            continue;

        if (arr[i] > target)
            break;

        ds.push_back(arr[i]);
        findCombination(n, i + 1, target - arr[i], arr, ans, ds);
        ds.pop_back();
    }
}

vector<vector<int>> combinationSum(int n, vector<int> &arr, int target)
{
    sort(arr.begin(), arr.end());
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
    cout << "[ ";
    for (int i = 0; i < res.size(); i++)
    {
        cout << "[ ";
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << "]";
    }
    cout << " ]";
}