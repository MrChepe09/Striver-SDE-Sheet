#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

struct Job
{
    int id;
    int deadline;
    int profit;
};

bool static comparison(Job a, Job b)
{
    return (a.profit > b.profit);
}

pair<int, int> jobSchedulling(int n, vector<Job> arr)
{
    sort(arr.begin(), arr.end(), comparison);
    int maxDeadline = arr[0].deadline;

    for (int i = 1; i < n; i++)
        maxDeadline = max(maxDeadline, arr[i].deadline);

    vector<int> timeSlots(maxDeadline + 1);

    for (int i = 0; i <= maxDeadline; i++)
        timeSlots[i] = -1;

    int countJobs = 0, jobProfit = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = arr[i].deadline; j > 0; j--)
        {
            if (timeSlots[j] == -1)
            {
                timeSlots[j] = i;
                countJobs++;
                jobProfit += arr[i].profit;
                break;
            }
        }
    }
    return make_pair(countJobs, jobProfit);
}

int main()
{
    int n;
    cin >> n;
    vector<Job> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].id >> arr[i].deadline >> arr[i].profit;
    }
    pair<int, int> res = jobSchedulling(n, arr);
    cout << res.first << " " << res.second << endl;
}