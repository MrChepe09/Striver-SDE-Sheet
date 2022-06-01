#include <iostream>
#include <stack>
using namespace std;

stack<int> sort_stack(stack<int> &s)
{
    stack<int> tempst;
    while (!s.empty())
    {
        int tmp = s.top();
        s.pop();
        while (!tempst.empty() && tempst.top() > tmp)
        {
            s.push(tempst.top());
            tempst.pop();
        }
        tempst.push(tmp);
    }
    return tempst;
}

void sorted_insert(stack<int> &st, int temp)
{
    if (st.empty() || st.top() < temp)
    {
        st.push(temp);
        return;
    }

    int ele = st.top();
    st.pop();
    sorted_insert(st, temp);

    st.push(ele);
}

void sort_stack_recursion(stack<int> &st)
{
    if (!st.empty())
    {
        int temp = st.top();
        st.pop();

        sort_stack_recursion(st);
        sorted_insert(st, temp);
    }
}

int main()
{
    int n;
    cin >> n;
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        int item;
        cin >> item;
        st.push(item);
    }
    // sort_stack_recursion(st);
    st = sort_stack(st);
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}