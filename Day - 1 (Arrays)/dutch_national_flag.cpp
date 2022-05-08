#include <iostream>
using namespace std;

int *dutch_national_flag(int n, int arr[])
{
    int start = 0;
    int end = n - 1;
    int curr = 0;
    while (curr <= end)
    {
        if (arr[curr] == 0)
        {
            swap(arr[curr++], arr[start++]);
        }
        else if (arr[curr] == 2)
        {
            swap(arr[curr], arr[end--]);
        }
        else
        {
            curr++;
        }
    }
    return arr;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int *res = dutch_national_flag(n, arr);
    for (int i = 0; i < n; i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
}