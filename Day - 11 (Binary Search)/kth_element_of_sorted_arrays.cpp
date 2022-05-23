#include <iostream>
#include <vector>
using namespace std;

int find_kth_element(int m, int n, vector<int> arr1, vector<int> arr2, int k)
{
    if (m > n)
        return find_kth_element(n, m, arr2, arr1, k);

    int low = max(0, k - n), high = min(k, m);
    while (low <= high)
    {
        int cut1 = (low + high) >> 1;
        int cut2 = k - cut1;

        int l1 = (cut1 == 0) ? INT32_MIN : arr1[cut1 - 1];
        int l2 = (cut2 == 0) ? INT32_MIN : arr2[cut2 - 1];
        int r1 = (cut1 == m) ? INT32_MAX : arr1[cut1];
        int r2 = (cut2 == n) ? INT32_MAX : arr2[cut2];

        if (l1 <= r2 && l2 <= r1)
        {
            return max(l1, l2);
        }
        else if (l1 > r2)
            high = cut1 - 1;
        else
            low = cut1 + 1;
    }
    return 1;
}

int main()
{
    int n, m;
    cin >> m >> n;
    vector<int> arr1(m), arr2(n);
    for (int i = 0; i < m; i++)
    {
        cin >> arr1[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> arr2[i];
    }
    int k;
    cin >> k;
    int median = find_kth_element(m, n, arr1, arr2, k);
    cout << median << endl;
}