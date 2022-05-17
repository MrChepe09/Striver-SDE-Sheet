#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct meeting
{
    int start;
    int end;
    int pos;
};

bool static cmp(meeting m1, meeting m2)
{
    if (m1.end < m2.end)
        return true;
    else if (m1.end > m2.end)
        return false;
    else if (m1.pos < m2.pos)
        return true;
    return false;
}

vector<int> maxMeetings(int n, vector<int> start, vector<int> end)
{
    vector<meeting> res(n);
    for (int i = 0; i < n; i++)
    {
        res[i].start = start[i], res[i].end = end[i], res[i].pos = i + 1;
    }

    sort(res.begin(), res.end(), cmp);

    vector<int> ans;
    int limit = res[0].end;
    ans.push_back(res[0].pos);

    for (int i = 1; i < n; i++)
    {
        if (res[i].start > limit)
        {
            limit = res[i].end;
            ans.push_back(res[i].pos);
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> start(n), end(n);
    for (int i = 0; i < n; i++)
    {
        cin >> start[i] >> end[i];
    }
    vector<int> res = maxMeetings(n, start, end);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    cout << endl;
}