// Maximum Sum Subarray
#include <iostream>
#include <vector>
using namespace std;

int kadane_algorithm(int n, vector<int> arr)
{
    int max_curr = 0;
    int max_so_far = INT32_MIN;
    for (int i = 0; i < n; i++)
    {
        max_curr += arr[i];
        max_so_far = max(max_so_far, max_curr);
        max_curr = max(max_curr, 0);
    }
    return max_so_far;
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
    int ans = kadane_algorithm(n, arr);
    cout << ans << endl;
}