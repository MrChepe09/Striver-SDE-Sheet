#include <iostream>
#include <vector>
using namespace std;

float find_median(int m, int n, vector<int> arr1, vector<int> arr2)
{
    if (m > n)
        return find_median(n, m, arr2, arr1);

    int low = 0, high = m, medianPlace = (m + n + 1) / 2;
    while (low <= high)
    {
        int cut1 = (low + high) >> 1;
        int cut2 = medianPlace - cut1;

        int l1 = (cut1 == 0) ? INT32_MIN : arr1[cut1 - 1];
        int l2 = (cut2 == 0) ? INT32_MIN : arr2[cut2 - 1];
        int r1 = (cut1 == m) ? INT32_MAX : arr1[cut1];
        int r2 = (cut2 == n) ? INT32_MAX : arr2[cut2];

        if (l1 <= r2 && l2 <= r1)
        {
            if ((m + n) % 2 != 0)
                return max(l1, l2);
            else
                return (max(l1, l2) + min(r1, r2)) / 2.0;
        }
        else if (l1 > r2)
            high = cut1 - 1;
        else
            low = cut1 + 1;
    }
    return 0.0;
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
    float median = find_median(m, n, arr1, arr2);
    cout << median << endl;
}