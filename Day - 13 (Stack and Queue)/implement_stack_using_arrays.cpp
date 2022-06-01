#include <iostream>
#include <vector>
using namespace std;

class Stack
{
    int size;
    int *arr;
    int top;

public:
    Stack()
    {
        top = -1;
        size = 1000;
        vector<int> arr(size);
    }

    void push(int x)
    {
        top++;
        arr[top] = x;
    }

    int pop()
    {
        int x = arr[top];
        top--;
        return x;
    }

    int Top()
    {
        int x = arr[top];
        return x;
    }

    int Size()
    {
        return top + 1;
    }
};

int main()
{
    Stack s;
    s.push(6);
    s.push(3);
    s.push(5);

    cout << "Size: " << s.Size() << endl;
    cout << "Top: " << s.Top() << endl;
    s.pop();
    cout << "Size: " << s.Size() << endl;
    cout << "Top: " << s.Top() << endl;
    s.pop();
    cout << "Size: " << s.Size() << endl;
    cout << "Top: " << s.Top() << endl;
}