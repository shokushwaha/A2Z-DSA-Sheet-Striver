long long getMaxArea(long long arr[], int n)
{
    // smaller to left
    vector<long long> left;
    stack<pair<long long, long long>> s1;
    for (int i = 0; i < n; i++)
    {
        if (s1.size() == 0)
            left.push_back(-1);

        else if (s1.top().first < arr[i])
            left.push_back(s1.top().second);

        else if (s1.size() && s1.top().first >= arr[i])
        {
            while (s1.size() && s1.top().first >= arr[i])
                s1.pop();

            if (s1.size() == 0)
                left.push_back(-1);

            else
                left.push_back(s1.top().second);
        }
        s1.push({arr[i], i});
    }

    // smaller to right
    vector<long long> right;
    stack<pair<long long, long long>> s2;
    for (int i = n - 1; i >= 0; i--)
    {
        if (s2.size() == 0)
            right.push_back(n);

        else if (s2.top().first < arr[i])
            right.push_back(s2.top().second);

        else if (s2.size() && s2.top().first >= arr[i])
        {
            while (s2.size() && s2.top().first >= arr[i])
                s2.pop();

            if (s2.size() == 0)
                right.push_back(n);
            else
                right.push_back(s2.top().second);
        }
        s2.push({arr[i], i});
    }
    reverse(right.begin(), right.end());

    // res=right-left-1
    vector<long long> res;

    for (int i = 0; i < n; i++)
    {
        int x = right[i] - left[i] - 1;
        res.push_back(x);
    }
    long long maxi = -1e7;

    // res*arr[i]
    for (int i = 0; i < n; i++)
    {
        long long area = res[i] * arr[i];
        maxi = max(maxi, area);
    }

    return maxi;
}