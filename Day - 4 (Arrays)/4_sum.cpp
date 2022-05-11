#include <iostream>
#include <vector>
using namespace std;

vector<int> four_sum(int n, vector<int> arr, int target)
{
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        int target1 = target - arr[i];
        for (int j = i + 1; j < n; j++)
        {
            int target2 = target1 - arr[j];
            int start = j + 1, end = n - 1;
            while (start < end)
            {
                if (arr[start] + arr[end] == target2)
                {
                    ans.push_back(i);
                    ans.push_back(j);
                    ans.push_back(start);
                    ans.push_back(end);
                    return ans;
                }
                else if (arr[start] + arr[end] > target2)
                {
                    end--;
                }
                else
                {
                    start++;
                }
            }
        }
    }
    return ans;
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
    int target;
    cin >> target;
    vector<int> res = four_sum(n, arr, target);
    cout << res[0] << " " << res[1] << " " << res[2] << " " << res[3] << endl;
}