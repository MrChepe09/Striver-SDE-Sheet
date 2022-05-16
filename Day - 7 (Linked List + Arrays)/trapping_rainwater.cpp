#include <iostream>
#include <vector>
using namespace std;

int trapped_water_optimized(int n, vector<int> arr)
{
    int left = 0, right = n - 1;
    int maxLeft = 0, maxRight = 0, res = 0;
    while (left <= right)
    {
        if (arr[left] <= arr[right])
        {
            if (arr[left] >= maxLeft)
            {
                maxLeft = arr[left];
            }
            else
            {
                res += maxLeft - arr[left];
            }
            left++;
        }
        else
        {
            if (arr[right] >= maxRight)
            {
                maxRight = arr[right];
            }
            else
            {
                res += maxRight - arr[right];
            }
            right--;
        }
    }
    return res;
}

int trapped_water(int n, vector<int> arr)
{
    vector<int> prefix(n), suffix(n);
    prefix[0] = arr[0];
    for (int i = 1; i < n; i++)
        prefix[i] = max(prefix[i - 1], arr[i]);

    suffix[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
        suffix[i] = max(suffix[i + 1], arr[i]);

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += min(suffix[i], prefix[i]) - arr[i];
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
    int ans = trapped_water_optimized(n, arr);
    cout << ans << endl;
}
