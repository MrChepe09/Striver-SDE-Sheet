#include <iostream>
#include <vector>
#include <map>
using namespace std;

// Using Moore's Voting Algorithm
int majority_element_optimized(int n, vector<int> arr)
{
    int count = 0;
    int ele = -1;
    for (int i = 0; i < n; i++)
    {
        if (count == 0)
        {
            ele = arr[i];
        }
        if (ele == arr[i])
        {
            count++;
        }
        else
        {
            count--;
        }
    }
    return ele;
}

// Using Map
int majority_element(int n, vector<int> arr)
{
    map<int, int> freq;
    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }
    for (auto i = freq.begin(); i != freq.end(); i++)
    {
        if (i->second > n / 2)
        {
            return i->first;
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
    int res = majority_element(n, arr);
    cout << res << endl;
}