#include <iostream>
#include <vector>
using namespace std;

bool isPossible(int n, vector<int> pages, int mid, int s)
{
    int cnt = 0;
    int sumAllocated = 0;
    for (int i = 0; i < n; i++)
    {
        if (sumAllocated + pages[i] > mid)
        {
            cnt++;
            sumAllocated = pages[i];
            if (sumAllocated > mid)
                return false;
        }
        else
        {
            sumAllocated += pages[i];
        }
    }
    if (cnt < s)
        return true;
    return false;
}

int allocate_pages(int n, vector<int> pages, int s)
{
    if (n < s)
        return -1;

    int low = pages[0];
    int high = 0;
    for (int i = 0; i < n; i++)
    {
        high += pages[i];
        low = min(low, pages[i]);
    }

    while (low <= high)
    {
        int mid = (low + high) >> 1;
        if (isPossible(n, pages, mid, s))
            high = mid - 1;
        else
            low = mid + 1;
    }
    return low;
}

int main()
{
    int n;
    cin >> n;
    vector<int> pages(n);
    for (int i = 0; i < n; i++)
    {
        cin >> pages[i];
    }
    int students;
    cin >> students;
    int minPages = allocate_pages(n, pages, students);
    cout << minPages << endl;
}