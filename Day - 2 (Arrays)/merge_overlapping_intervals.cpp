#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> merge_intervals(int n, vector<vector<int>> arr)
{
    sort(arr.begin(), arr.end());
    vector<vector<int>> merged;
    for (int i = 0; i < n; i++)
    {
        if (merged.empty() || merged.back()[1] < arr[i][0])
        {
            merged.push_back({arr[i][0], arr[i][1]});
        }
        else
        {
            merged.back()[1] = max(merged.back()[1], arr[i][1]);
        }
    }
    return merged;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> arr;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        arr.push_back({a, b});
    }
    vector<vector<int>> res = merge_intervals(n, arr);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i][0] << " " << res[i][1] << endl;
    }
}
