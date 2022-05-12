#include <iostream>
#include <vector>
using namespace std;

// O(n-1) OR O(m-1)
int unique_grid_paths_optimized(int n, int m)
{
    int N = n - 1 + m - 1;
    int r = (n < m) ? n - 1 : m - 1;
    long res = 1;
    long j = 1;
    for (long i = N; i > N - r; i--, j++)
    {
        res *= i;
        res /= j;
    }
    return res;
}

// DP Approach - O(n*m)
int unique_grid_paths(int i, int j, int n, int m, vector<vector<int>> &dp)
{
    if (i == n - 1 && j == m - 1)
    {
        return 1;
    }
    if (i >= n || j >= m)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    else
    {
        return dp[i][j] = unique_grid_paths(i + 1, j, n, m, dp) + unique_grid_paths(i, j + 1, n, m, dp);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    int res = unique_grid_paths(0, 0, n, m, dp);
    int res2 = unique_grid_paths_optimized(n, m);
    cout << res2 << endl;
}
