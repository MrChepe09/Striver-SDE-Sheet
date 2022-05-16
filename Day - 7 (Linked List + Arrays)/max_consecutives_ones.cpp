#include <iostream>
#include <vector>
using namespace std;

int maxConsecutive(int n, vector<int> arr)
{
    int cnt = 0;
    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
            cnt++;
        else
            cnt = 0;

        maxi = max(maxi, cnt);
    }
    return maxi;
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
    int ans = maxConsecutive(n, arr);
    cout << ans << endl;
}