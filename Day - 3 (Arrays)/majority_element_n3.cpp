#include <iostream>
#include <vector>
#include <map>
using namespace std;

// Using Extended Moore's Voting Algorithm
int majority_element_optimized(int n, vector<int> arr)
{
    int count1 = 0, count2 = 0;
    int ele1 = -1, ele2 = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == ele1)
        {
            count1++;
        }
        else if (arr[i] == ele2)
        {
            count2++;
        }
        else if (count1 == 0)
        {
            ele1 = arr[i];
            count1 = 1;
        }
        else if (count2 == 0)
        {
            ele2 = arr[i];
            count2 = 1;
        }
        else
        {
            count1--;
            count2--;
        }
    }
    count1 = count2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == ele1)
        {
            count1++;
        }
        else if (arr[i] == ele2)
        {
            count2++;
        }
    }
    if (count1 > n / 3)
    {
        cout << ele1 << endl;
    }
    if (count2 > n / 3)
    {
        cout << ele2 << endl;
    }
}

// Using Map
void majority_element(int n, vector<int> arr)
{
    map<int, int> freq;
    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }
    for (auto i = freq.begin(); i != freq.end(); i++)
    {
        if (i->second > n / 3)
        {
            cout << i->first << " ";
        }
        cout << endl;
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
    majority_element_optimized(n, arr);
}