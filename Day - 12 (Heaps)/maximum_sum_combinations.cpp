#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> maximum_c_combinations(int n, vector<int> arr1, vector<int> arr2, int c)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    sort(arr1.begin(), arr1.end(), greater<int>());
    sort(arr2.begin(), arr2.end(), greater<int>());
    for (int i = 0; i < c; i++)
        pq.push(arr1[i] + arr2[i]);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                if (arr1[i] + arr2[j] > pq.top())
                {
                    pq.pop();
                    pq.push(arr1[i] + arr2[j]);
                }
                else
                {
                    break;
                }
            }
        }
    }
    vector<int> ans;
    while (!pq.empty())
    {
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr1(n), arr2(n);
    for (int i = 0; i < n; i++)
        cin >> arr1[i];

    for (int i = 0; i < n; i++)
        cin >> arr2[i];

    int c;
    cin >> c;

    vector<int> res = maximum_c_combinations(n, arr1, arr2, c);
    for (int i = 0; i < c; i++)
        cout << res[i] << " ";
    cout << endl;
}