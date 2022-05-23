#include <iostream>
#include <vector>
using namespace std;

int countSmallerThanMid(vector<int> row, int m)
{
    int l = 0, h = row.size() - 1;
    while (l <= m)
    {
        int mid = (l + h) >> 1;
        if (row[mid] <= mid)
        {
            l = mid + 1;
        }
        else
        {
            h = mid - 1;
        }
    }
    return l;
}

int matrix_median(int n, int m, vector<vector<int>> mat)
{
    int low = 1, high = 1e9;
    while (low <= high)
    {
        int mid = (low + high) >> 1;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            cnt += countSmallerThanMid(mat[i], mid);
        }

        if (cnt <= (n * m) / 2)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m, -1));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; i < m; j++)
        {
            cin >> mat[i][j];
        }
    }
    int median = matrix_median(n, m, mat);
    cout << median << endl;
}