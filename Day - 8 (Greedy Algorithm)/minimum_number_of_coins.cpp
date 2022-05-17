#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> minimum_coins(int n, vector<int> coins)
{
    vector<int> res;
    for (int i = coins.size() - 1; i >= 0; i--)
    {
        while (n >= coins[i])
        {
            n -= coins[i];
            res.push_back(coins[i]);
        }
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    vector<int> ans = minimum_coins(n, coins);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}