#include <iostream>
#include <vector>
using namespace std;

void min_heapify(vector<int> &arr, int n, int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i)
    {
        swap(arr[i], arr[smallest]);
        min_heapify(arr, n, smallest);
    }
}

void max_heapify(vector<int> &arr, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        max_heapify(arr, n, largest);
    }
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

    // Heap Sort - ascending
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        max_heapify(arr, n, i);
    }
    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        max_heapify(arr, i, 0);
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Heap Sort - descending
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        min_heapify(arr, n, i);
    }
    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        min_heapify(arr, i, 0);
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}