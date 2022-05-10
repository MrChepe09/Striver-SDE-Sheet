#include <iostream>
#include <vector>
using namespace std;

int merge(int n, vector<int> &arr, vector<int> &temp, int left, int mid, int right)
{
    int count = 0;
    int j = mid;
    for (int i = left; i < mid; i++)
    {
        while (j <= right && arr[i] > (2 * arr[j]))
        {
            j++;
        }
        cout << arr[i] << " " << i << " " << arr[j] << " " << j << endl;
        count += (j - (mid));
    }
    int i = left;
    j = mid;
    int k = left;
    while (i <= mid - 1 && j <= right)
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
        }
    }
    while (i <= mid - 1)
    {
        temp[k++] = arr[i++];
    }
    while (j <= right)
    {
        temp[k++] = arr[j++];
    }
    for (int i = left; i <= right; i++)
    {
        arr[i] = temp[i];
    }
    return count;
}

int count_reverse_pairs(int n, vector<int> &arr, vector<int> &temp, int left, int right)
{
    int count = 0;
    if (left < right)
    {
        int mid = (left + (right - left) / 2);
        count += count_reverse_pairs(n, arr, temp, left, mid);
        count += count_reverse_pairs(n, arr, temp, mid + 1, right);

        count += merge(n, arr, temp, left, mid + 1, right);
    }
    return count;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> temp(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int res = count_reverse_pairs(n, arr, temp, 0, n - 1);
    cout << res << endl;
}