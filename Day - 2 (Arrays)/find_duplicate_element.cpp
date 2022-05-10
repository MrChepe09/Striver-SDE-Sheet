#include <iostream>
#include <vector>
using namespace std;

// Using Slow-Fast Pointer
int find_duplicate_optimized(int n, vector<int> arr)
{
    int slow = arr[0];
    int fast = arr[0];
    do
    {
        slow = arr[slow];
        fast = arr[arr[fast]];
    } while (slow != fast);
    fast = arr[0];
    while (slow != fast)
    {
        fast = arr[fast];
        slow = arr[slow];
    }
    return slow;
}

// Using frequency array
int find_duplicate(int n, vector<int> arr)
{
    vector<int> freq(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        if (freq[arr[i]] == 0)
        {
            freq[arr[i]] += 1;
        }
        else
        {
            return arr[i];
        }
    }
    return -1;
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
    int dup = find_duplicate(n, arr);
    cout << dup << endl;
}