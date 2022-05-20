#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve(int index, vector<int> &arr, int n, vector<int> &res, int sum)
{
    if (index == n)
    {
        res.push_back(sum);
        return;
    }

    solve(index + 1, arr, n, res, sum + arr[index]);
    solve(index + 1, arr, n, res, sum);
}

vector<int> subset_sum(int n, vector<int> arr)
{
    vector<int> res;
    solve(0, arr, n, res, 0);
    return res;
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
    vector<int> res = subset_sum(n, arr);
    sort(res.begin(), res.end());
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
}