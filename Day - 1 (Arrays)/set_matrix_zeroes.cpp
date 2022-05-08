#include <iostream>
#include <vector>
using namespace std;

void set_matrix_zeroes_optimized(int r, int c, vector<vector<int>> &mat)
{
    int col0 = 1;
    for (int i = 0; i < r; i++)
    {
        if (mat[i][0] == 0)
        {
            col0 = 0;
        }
        for (int j = 1; j < c; j++)
        {
            if (mat[i][j] == 0)
            {
                mat[i][0] = 0;
                mat[0][j] = 0;
            }
        }
    }

    for (int i = r - 1; i >= 0; i--)
    {
        for (int j = c - 1; j >= 1; j--)
        {
            if (mat[i][0] == 0 || mat[0][j] == 0)
            {
                mat[i][j] = 0;
            }
        }
        if (col0 == 0)
        {
            mat[i][0] = 0;
        }
    }
}

void set_matrix_zeroes(int r, int c, vector<vector<int>> &mat)
{
    vector<int> row(r, -1);
    vector<int> col(c, -1);
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (mat[i][j] == 0)
            {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (row[i] == 1 || col[j] == 1)
            {
                mat[i][j] = 0;
            }
        }
    }
}

int main()
{
    int row, col;
    cin >> row >> col;
    vector<vector<int>> mat(row, vector<int>(col, 0));
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> mat[i][j];
        }
    }
    set_matrix_zeroes_optimized(row, col, mat);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}