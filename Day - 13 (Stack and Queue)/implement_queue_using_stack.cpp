#include <iostream>
#include <stack>
using namespace std;

class MyQueue
{
public:
    stack<int> input, output;

    void push(int x)
    {
        input.push(x);
    }

    int pop()
    {
        if (output.empty())
            while (input.size())
                output.push(input.top()), input.pop();

        int x = output.top();
        output.pop();
        return x;
    }

    int top()
    {
        if (output.empty())
            while (input.size())
                output.push(input.top()), input.pop();
        return output.top();
    }

    int size()
    {
        return (output.size() + input.size());
    }
};
int main()
{
    MyQueue q;
    q.push(3);
    q.push(4);
    q.push(5);
    cout << "Size: " << q.size() << endl;
    cout << "Top: " << q.top() << endl;
    q.pop();
    cout << "Size: " << q.size() << endl;
    cout << "Top: " << q.top() << endl;
    q.pop();
    cout << "Size: " << q.size() << endl;
    cout << "Top: " << q.top() << endl;
}