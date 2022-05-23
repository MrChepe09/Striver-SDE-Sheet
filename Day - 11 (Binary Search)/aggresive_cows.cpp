#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPossible(int n, vector<int> s, int c, int mid)
{
    int cnt = 1;
    int lastCow = s[0];
    for (int i = 1; i < n; i++)
    {
        if (s[i] - lastCow >= mid)
        {
            cnt++;
            lastCow = s[i];
        }
    }
    if (cnt >= c)
        return true;
    return false;
}

int aggresive_cows(int n, vector<int> s, int c)
{
    sort(s.begin(), s.end());
    int low = 1;
    int high = s[n - 1] - s[0];

    while (low <= high)
    {
        int mid = (low + high) >> 1;
        if (isPossible(n, s, c, mid))
            low = mid + 1;
        else
            high = mid - 1;
    }
    return high;
}

int main()
{
    int n;
    cin >> n;
    vector<int> stall(n);
    for (int i = 0; i < n; i++)
        cin >> stall[i];
    int cows;
    cin >> cows;
    int ans = aggresive_cows(n, stall, cows);
    cout << ans << endl;
}