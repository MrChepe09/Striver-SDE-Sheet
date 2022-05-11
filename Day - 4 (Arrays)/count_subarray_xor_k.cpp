#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int count_subarray_xor_k(int n, vector<int> arr, int equal)
{
    int count = 0;
    int prefix_xor = 0;
    unordered_map<int, int> umap;
    for (int i = 0; i < n; i++)
    {
        prefix_xor ^= arr[i];
        if (prefix_xor == equal)
        {
            count++;
        }
        int h = prefix_xor ^ equal;
        if (umap.find(h) != umap.end())
        {
            count += umap[h];
        }
        umap[h]++;
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
    int equal;
    cin >> equal;
    int count = count_subarray_xor_k(n, arr, equal);
    cout << count << endl;
}