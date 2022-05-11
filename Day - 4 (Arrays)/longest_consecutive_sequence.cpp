#include <iostream>
#include <vector>
#include <set>
using namespace std;

int longest_consecutive_seq(int n, vector<int> arr)
{
    set<int> elem;
    int maxlen = 0;
    for (int ele : arr)
    {
        elem.insert(ele);
    }
    for (int i = 0; i < n; i++)
    {
        if (!elem.count(arr[i] - 1))
        {
            int ele = arr[i];
            int elecount = 1;
            while (elem.count(ele + 1))
            {
                ele += 1;
                elecount += 1;
            }
            maxlen = max(maxlen, elecount);
        }
    }
    return maxlen;
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
    int len = longest_consecutive_seq(n, arr);
    cout << len << endl;
}