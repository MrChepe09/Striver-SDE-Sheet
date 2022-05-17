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

bool static comparator(meeting m1, meeting m2)
{
    if (m1.end < m2.end)
        return true;
    else if (m1.end > m2.end)
        return false;
    else if (m1.pos < m2.pos)
        return true;
    return false;
}

int n_meetings(int n, vector<int> start, vector<int> end)
{
    vector<int> res;
    vector<meeting> meets(n);
    for (int i = 0; i < n; i++)
    {
        meets[i].start = start[i];
        meets[i].end = end[i];
        meets[i].pos = i + 1;
    }
    sort(meets.begin(), meets.end(), comparator);

    int limit = meets[0].end;
    res.push_back(meets[0].pos);
    for (int i = 1; i < n; i++)
    {
        if (meets[i].start > limit)
        {
            limit = meets[i].end;
            res.push_back(meets[i].pos);
        }
    }
    // for (int i = 0; i < res.size(); i++)
    // {
    //     cout << res[i] << " ";
    // }
    // return res.size();
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
    int ans = n_meetings(n, start, end);
    cout << ans << endl;
}