#include <iostream>
#include <vector>
using namespace std;

// Normal Approach:- XOR all elements, we will
// get the single element

int find_element(int n, vector<int> arr)
{
    int low = 0, high = n - 2;
    while (low <= high)
    {
        int mid = (low + high) >> 1;
        if (mid % 2 == 0)
        {
            if (arr[mid] != arr[mid + 1])
                high = mid - 1;
            else
                low = mid + 1;
        }
        else
        {
            if (arr[mid] == arr[mid + 1])
                high = mid - 1;
            else
                low = mid + 1;
        }
    }
    return arr[low];
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
    int ele = find_element(n, arr);
    cout << ele << endl;
}