#include <iostream>
using namespace std;

double implement_pow(double x, long long n)
{
    long long nn = n;
    double ans = 1.0;
    if (nn < 0)
    {
        nn *= -1;
    }
    while (nn > 0)
    {
        if (nn % 2)
        {
            ans *= x;
            nn -= 1;
        }
        else
        {
            x *= x;
            nn = nn / 2;
        }
    }
    if (n < 0)
    {
        ans = (double)(1.0) / (double)(ans);
    }
    return ans;
}

int main()
{
    double x;
    cin >> x;
    long long n;
    cin >> n;
    double res = implement_pow(x, n);
    cout << res << endl;
}