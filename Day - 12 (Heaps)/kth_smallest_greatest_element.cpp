#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int kth_smallest(int n, vector<int> arr, int k)
{
    priority_queue<int> pq;
    for (int i = 0; i < k; i++)
        pq.push(arr[i]);

    for (int i = k; i < n; i++)
    {
        if (arr[i] < pq.top())
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }
    return pq.top();
}

int kth_greatest(int n, vector<int> arr, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < k; i++)
        pq.push(arr[i]);

    for (int i = k; i < n; i++)
    {
        if (arr[i] > pq.top())
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }
    return pq.top();
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int k;
    cin >> k;
    int kthSmallest = kth_smallest(n, arr, k);
    int kthLargest = kth_greatest(n, arr, k);
    cout << kthSmallest << " " << kthLargest << endl;
}