#include <iostream>
#include <vector>
using namespace std;

class Queue
{
    int front, back;
    int currSize, maxSize;

public:
    vector<int> arr;
    Queue()
    {
        front = -1, back = -1;
        currSize = 0;
        maxSize = 6;
        arr.resize(maxSize);
    }

    void enqueue(int x)
    {
        if (currSize == maxSize)
            return;
        if (back == -1)
        {
            front = 0;
            back = 0;
        }
        else
            back = (back + 1) % maxSize;
        arr[back] = x;
        currSize++;
    }

    int dequeue()
    {
        if (front == -1)
            return -1;
        int popped = arr[front];

        if (currSize == 1)
        {
            front = -1;
            back = -1;
        }
        else
            front = (front + 1) % maxSize;
        currSize--;
        return popped;
    }

    int Top()
    {
        if (front == -1)
            return -1;
        return arr[front];
    }

    int Size()
    {
        return currSize;
    }
};

int main()
{
    Queue q;

    q.enqueue(4);
    q.enqueue(14);
    q.enqueue(24);
    q.enqueue(34);

    cout << "Size: " << q.Size() << endl;
    cout << "Top: " << q.Top() << endl;
    q.dequeue();
    cout << "Size: " << q.Size() << endl;
    cout << "Top: " << q.Top() << endl;
    q.dequeue();
    cout << "Size: " << q.Size() << endl;
    cout << "Top: " << q.Top() << endl;
    q.dequeue();
    cout << "Size: " << q.Size() << endl;
    cout << "Top: " << q.Top() << endl;
}