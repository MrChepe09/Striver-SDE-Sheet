#include <iostream>
#include <vector>
using namespace std;

int stock_buy_sell(int n, vector<int> prices)
{
    int maxProfit = 0;
    int minBuy = prices[0];
    for (int i = 1; i < n; i++)
    {
        maxProfit = max(maxProfit, prices[i] - minBuy);
        minBuy = min(prices[i], minBuy);
    }
    return maxProfit;
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
    int maxProfit = stock_buy_sell(n, arr);
    cout << maxProfit << endl;
}