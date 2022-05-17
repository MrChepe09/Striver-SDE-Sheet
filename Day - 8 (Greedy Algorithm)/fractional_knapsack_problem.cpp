#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct item
{
    int value;
    int weight;
};

bool static cmp(item a, item b)
{
    double r1 = (double)a.value / (double)a.weight;
    double r2 = (double)b.value / (double)b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int n, int W, vector<item> arr)
{
    sort(arr.begin(), arr.end(), cmp);

    int currWeight = 0;
    double finalValue = 0.0;

    for (int i = 0; i < n; i++)
    {
        if (currWeight + arr[i].weight <= W)
        {
            currWeight += arr[i].weight;
            finalValue += arr[i].value;
        }
        else
        {
            int remain = W - currWeight;
            finalValue += (arr[i].value / (double)arr[i].weight) * (double)remain;
            break;
        }
    }
    return finalValue;
}

int main()
{
    int n;
    cin >> n;
    int weight;
    cin >> weight;
    vector<item> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].value >> arr[i].weight;
    }

    double ans = fractionalKnapsack(n, weight, arr);
    cout << ans << endl;
}
