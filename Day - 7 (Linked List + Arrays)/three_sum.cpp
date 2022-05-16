#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> threesum(int n, vector<int> arr, int target)
{
    vector<vector<int>> res;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < (int)(n - 2); i++)
    {
        if (i == 0 || (i > 0 && arr[i] != arr[i - 1]))
        {
            int low = i + 1, high = n - 1, sum = 0 - arr[i];
            while (low < high)
            {
                if (arr[low] + arr[high] == sum)
                {
                    res.push_back({arr[i], arr[low], arr[high]});

                    while (low < high && arr[low] == arr[low + 1])
                        low++;
                    while (low < high && arr[high] == arr[high - 1])
                        high--;
                    low++;
                    high--;
                }
                else if (arr[low] + arr[high] < sum)
                    low++;
                else
                    high--;
            }
        }
    }
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
    vector<vector<int>> ans;
    int target;
    cin >> target;
    ans = threesum(n, arr, target);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}