#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<double> find_medians(int n, vector<int> arr)
{
    vector<double> res;
    priority_queue<int> maxh;
    priority_queue<int, vector<int>, greater<int>> minh;

    res.push_back(arr[0]);
    maxh.push(arr[0]);
    for (int i = 1; i < n; i++)
    {
        maxh.push(arr[i]);
        minh.push(maxh.top());
        maxh.pop();

        if (minh.size() > maxh.size())
        {
            maxh.push(minh.top());
            minh.pop();
        }

        if (maxh.size() == minh.size())
            res.push_back(((double)(maxh.top()) + (double)(minh.top())) / 2);
        else
            res.push_back((double)maxh.top());
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<double> ans = find_medians(n, arr);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << endl;
}