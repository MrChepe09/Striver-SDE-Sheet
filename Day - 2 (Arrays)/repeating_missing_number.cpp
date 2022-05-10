#include <iostream>
#include <vector>
using namespace std;

// Using XOR
vector<int> missing_repeating_number_optimized(int n, vector<int> arr)
{
    int xor1, set_bit;
    int x = 0, y = 0;
    xor1 = arr[0];
    for (int i = 1; i < n; i++)
    {
        xor1 = xor1 ^ arr[i];
    }
    for (int i = 1; i <= n; i++)
    {
        xor1 = xor1 ^ i;
    }
    set_bit = xor1 & ~(xor1 - 1);
    for (int i = 0; i < n; i++)
    {
        if (arr[i] & set_bit)
        {
            x = x ^ arr[i];
        }
        else
        {
            y = y ^ arr[i];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (i & set_bit)
        {
            x = x ^ i;
        }
        else
        {
            y = y ^ i;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            return {x, y};
        }
    }
    return {y, x};
}

// Using Mathematics
vector<int> missing_repeating_number(int n, vector<int> arr)
{
    int sumSeq = (n * (n + 1)) / 2;
    int prodSeq = (n * (n + 1) * (2 * n + 1)) / 6;
    int missing = 0, repeating = 0;

    for (int i = 0; i < n; i++)
    {
        sumSeq -= arr[i];
        prodSeq -= (arr[i] * arr[i]);
    }

    missing = (sumSeq + (prodSeq / sumSeq)) / 2;
    repeating = missing - sumSeq;
    return {missing, repeating};
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
    vector<int> res = missing_repeating_number_optimized(n, arr);
    cout << res[0] << " " << res[1] << endl;
}