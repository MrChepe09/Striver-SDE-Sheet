#include <iostream>
#include <vector>
using namespace std;

bool find_element(int n, vector<int> arr, int target)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) >> 1;
        if (arr[mid] == target)
            return true;

        if (arr[low] <= arr[mid])
        {
            if (arr[low] <= target && arr[mid] >= target)
                high = mid - 1;
            else
                low = mid + 1;
        }
        else
        {
            if (arr[mid] <= target && arr[high] >= target)
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int target;
    cin >> target;
    bool present = find_element(n, arr, target);
    cout << present << endl;
}