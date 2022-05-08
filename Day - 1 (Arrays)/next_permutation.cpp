#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> next_permutation(int n, vector<int> arr)
{
    int k, l;
    for (k = n - 2; k >= 0; k--)
    {
        if (arr[k] < arr[k + 1])
        {
            break;
        }
    }
    if (k < 0)
    {
        reverse(arr.begin(), arr.end());
    }
    else
    {
        for (l = n - 1; l > k; l--)
        {
            if (arr[l] > arr[k])
            {
                break;
            }
        }
        swap(arr[k], arr[l]);
        reverse(arr.begin() + k + 1, arr.end());
    }
    return arr;
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
    vector<int> res = next_permutation(n, arr);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}