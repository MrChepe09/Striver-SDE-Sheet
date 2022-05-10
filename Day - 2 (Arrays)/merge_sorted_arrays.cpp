#include <iostream>
#include <vector>
using namespace std;

// Iterate over arr1 and compare each element with
// first element of arr2. If arr1[i] > arr2[0], then swap
// For each swap, correct arr2
void merge_array(int n, int m, vector<int> &arr1, vector<int> &arr2)
{
    for (int i = 0; i < n; i++)
    {
        bool swap = false;
        if (arr1[i] > arr2[0])
        {
            int temp = arr1[i];
            arr1[i] = arr2[0];
            arr2[0] = temp;
            swap = true;
        }

        if (swap)
        {
            int first = arr2[0];
            int k = 1;
            while (k < m && arr2[k] < first)
            {
                arr2[k - 1] = arr2[k];
                k++;
            }
            arr2[k - 1] = first;
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> arr1(n), arr2(m);
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> arr2[i];
    }
    merge_array(n, m, arr1, arr2);
    for (int i = 0; i < n; i++)
    {
        cout << arr1[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < m; i++)
    {
        cout << arr2[i] << " ";
    }
    cout << endl;
}