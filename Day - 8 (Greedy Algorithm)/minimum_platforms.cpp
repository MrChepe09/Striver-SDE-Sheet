#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minimum_platforms(int n, vector<int> arr, vector<int> dep)
{
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());

    int plat = 1, count = 1;
    int i = 1, j = 0;
    while (i < n && j < n)
    {
        if (arr[i] <= dep[j])
        {
            count++;
            i++;
        }
        else
        {
            count--;
            j++;
        }
        plat = max(plat, count);
    }
    return plat;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n), dep(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i] >> dep[i];
    }
    int ans = minimum_platforms(n, arr, dep);
    cout << ans << endl;
}