#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool balanced_parenthesis(string s)
{
    stack<char> st;
    for (auto it : s)
    {
        if (it == '(' || it == '[' || it == '{')
            st.push(it);
        else
        {
            if (st.size() == 0)
                return false;
            char ch = st.top();
            st.pop();
            if ((it == ')' && ch == '(') || (it == ']' && ch == '[') || (it == '}' && ch == '{'))
                continue;
            else
                return false;
        }
    }
    return st.empty();
}

int main()
{
    string s;
    cin >> s;
    bool ans = balanced_parenthesis(s);
    cout << ans << endl;
}