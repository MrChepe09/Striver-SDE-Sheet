#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> next_greater(int n, vector<int> arr)
{
    vector<int> res(n, -1);
    stack<int> st;
    for (int i = 2 * n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() <= arr[i % n])
            st.pop();

        if (i < n)
            if (!st.empty())
                res[i] = st.top();
        st.push(arr[i % n]);
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<int> res = next_greater(n, arr);
    for (int i = 0; i < n; i++)
        cout << res[i] << " ";
    cout << endl;
}