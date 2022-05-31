#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Using STL
void maxHeap()
{
    priority_queue<int> pq;
    pq.push(5);
    pq.push(2);
    pq.push(8);
    pq.push(7);
    pq.push(1);

    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}

void minHeap()
{
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(5);
    pq.push(2);
    pq.push(8);
    pq.push(7);
    pq.push(1);

    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}

int main()
{
    maxHeap();
    minHeap();
}