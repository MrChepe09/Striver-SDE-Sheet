#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string kth_permutation(int n, int k)
{
    vector<int> nums;
    int fact = 1;
    for (int i = 1; i < n; i++)
    {
        fact *= i;
        nums.push_back(i);
    }
    nums.push_back(n);
    string ans = "";
    k -= 1;
    while (true)
    {
        ans += to_string(nums[k / fact]);
        nums.erase(nums.begin() + k / fact);
        if (nums.size() == 0)
        {
            break;
        }
        k = k % fact;
        fact /= nums.size();
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    int k;
    cin >> k;
    string res = kth_permutation(n, k);
    for (int i = 0; i < n; i++)
    {
        cout << res[i];
    }
    cout << endl;
}