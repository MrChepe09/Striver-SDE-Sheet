#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// for clockwise - Transpose -> Reverse
// for anticlockwise - Reverse -> Transpose
void rotate_matrix(int r, int c, vector<vector<int>> &mat)
{
    // Transposing matrix
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < i; j++)
        {
            swap(mat[i][j], mat[j][i]);
        }
    }
    // Reversing each row
    for (int i = 0; i < r; i++)
    {
        reverse(mat[i].begin(), mat[i].end());
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
    rotate_matrix(row, col, mat);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}