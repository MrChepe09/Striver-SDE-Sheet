#include <iostream>
#include <vector>
using namespace std;

int merge(vector<int> &arr, vector<int> &temp, int left, int mid, int right)
{
    int count = 0;
    int i = left, j = mid, k = left;
    while ((i <= mid - 1) && (j <= right))
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            count = count + (mid - i);
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

int count_inversions(vector<int> &arr, vector<int> &temp, int left, int right)
{
    int mid, count = 0;
    if (right > left)
    {
        mid = (left + right) / 2;
        count += count_inversions(arr, temp, left, mid);
        count += count_inversions(arr, temp, mid + 1, right);
        count += merge(arr, temp, left, mid + 1, right);
    }
    return count;
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
    vector<int> temp(n);
    int ans = count_inversions(arr, temp, 0, n - 1);
    cout << ans << endl;
}