static bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}
int maxMeetings(int start[], int end[], int n)
{
    vector<pair<int, int>> arr; // <start_time,end_time>

    for (int i = 0; i < n; i++)
    {
        pair<int, int> x = make_pair(start[i], end[i]);
        arr.push_back(x);
    }

    sort(arr.begin(), arr.end(), cmp);

    int cnt = 1;
    int ansEnd = arr[0].second;
    for (int i = 1; i < arr.size(); i++)
    {
        // another meeting is possible when the start time of second meeting is greater than the end time of first meeting
        if (arr[i].first > ansEnd)
        {
            cnt++;
            ansEnd = arr[i].second;
        }
    }
    return cnt;
}