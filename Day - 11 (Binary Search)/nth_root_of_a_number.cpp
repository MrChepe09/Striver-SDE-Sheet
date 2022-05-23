#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

double multiply(double number, double n)
{
    double ans = 1.0;
    for (int i = 0; i < n; i++)
    {
        ans *= number;
    }
    return ans;
}

double nth_root(int n, int m)
{
    double low = 1, high = m;
    double eps = 1e-6;
    while ((high - low) > eps)
    {
        double mid = (low + high) / 2.0;
        if (multiply(mid, n) < m)
        {
            low = mid;
        }
        else
        {
            high = mid;
        }
    }
    return low;
}

int main()
{
    int n, m;
    cin >> n >> m;
    double res = nth_root(n, m);
    cout << res << endl;
}
