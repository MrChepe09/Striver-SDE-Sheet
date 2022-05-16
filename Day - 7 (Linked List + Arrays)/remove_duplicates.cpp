#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(int n, vector<int> &arr)
{
    int i = 0;
    for (int j = 1; j < n; j++)
    {
        if (arr[i] != arr[j])
        {
            i++;
            arr[i] = arr[j];
        }
    }
    return i + 1;
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
    int res = removeDuplicates(n, arr);
    for (int i = 0; i < res; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}