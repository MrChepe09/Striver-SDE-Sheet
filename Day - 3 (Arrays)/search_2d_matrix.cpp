#include <iostream>
#include <vector>
using namespace std;

// Using sorted matrix in advantage
bool search_matrix_2(int n, int m, vector<vector<int>> arr, int target)
{
    int x = 0, y = m - 1;
    while (x < n && y >= 0)
    {
        if (arr[x][y] == target)
        {
            return true;
        }
        else if (arr[x][y] > target)
        {
            y--;
        }
        else
        {
            x++;
        }
    }
    return false;
}

// Binary Search
bool search_matrix(int n, int m, vector<vector<int>> arr, int target)
{
    int start = 0, end = (n * m) - 1;
    while (start <= end)
    {
        int mid = (start + (end - start) / 2);
        if (arr[mid / m][mid % m] == target)
        {
            return true;
        }
        else if (arr[mid / m][mid % m] > target)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    int target;
    cin >> target;
    bool res = search_matrix_2(n, m, arr, target);
    cout << res << endl;
}