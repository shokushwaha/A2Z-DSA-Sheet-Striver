vector<vector<int>> overlappedInterval(vector<vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end());

    stack<pair<int, int>> s;

    s.push({intervals[0][0], intervals[0][1]});

    for (int i = 1; i < intervals.size(); i++)
    {
        int start1 = s.top().first;
        int end1 = s.top().second;

        int start2 = intervals[i][0];
        int end2 = intervals[i][1];

        if (end1 < start2)
        {
            s.push({start2, end2});
        }
        else
        {
            s.pop();
            int d = max(end1, end2);
            s.push({start1, d});
        }
    }
    vector<vector<int>> ans;

    while (!s.empty())
    {
        ans.push_back({s.top().first, s.top().second});
        s.pop();
    }
    sort(ans.begin(), ans.end());
    return ans;
}