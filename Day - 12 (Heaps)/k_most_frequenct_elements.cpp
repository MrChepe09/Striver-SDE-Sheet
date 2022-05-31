#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

typedef pair<int, int> pii;

vector<int> k_frequent_elements(int n, vector<int> arr, int k)
{
    unordered_map<int, int> umap;
    for (int i = 0; i < n; i++)
        umap[arr[i]]++;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for (auto it : umap)
    {
        pq.push({it.second, it.first});
        if (pq.size() > k)
            pq.pop();
    }

    vector<int> ans;
    while (!pq.empty())
    {
        ans.push_back(pq.top().second);
        pq.pop();
    }
    return ans;
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
    vector<int> res = k_frequent_elements(n, arr, k);
    for (int i = 0; i < n; i++)
        cout << res[i];
    cout << endl;
}
