// recursion
int solve(vector<vector<int>> &points, int day, int prevIndex)
{
    if (day < 0)
        return 0;
    if (day == 0)
    {
        int maxi = 0;
        for (int i = 0; i < 3; i++)
        {
            if (i != prevIndex)
                maxi = max(maxi, points[day][i]);
        }
        return maxi;
    }

    int maxi = 0;
    for (int i = 0; i < 3; i++)
    {
        if (i != prevIndex)
        {
            int ans = points[day][i] + solve(points, day - 1, i);
            maxi = max(ans, maxi);
        }
    }
    return maxi;
}
int maximumPoints(vector<vector<int>> &points, int n)
{
    vector<vector<int>> dp(n, vector<int>(4, -1));
    return solve(points, n - 1, 3, dp);
}

// dp - memoization
int solve(vector<vector<int>> &points, int day, int prevIndex, vector<vector<int>> &dp)
{
    if (day < 0)
        return 0;
    if (day == 0)
    {
        int maxi = 0;
        for (int i = 0; i < 3; i++)
        {
            if (i != prevIndex)
                maxi = max(maxi, points[day][i]);
        }
        return maxi;
    }
    if (dp[day][prevIndex] != -1)
        return dp[day][prevIndex];

    int maxi = 0;
    for (int i = 0; i < 3; i++)
    {
        if (i != prevIndex)
        {
            int ans = points[day][i] + solve(points, day - 1, i, dp);
            maxi = max(ans, maxi);
        }
    }
    return dp[day][prevIndex] = maxi;
}
int maximumPoints(vector<vector<int>> &points, int n)
{
    vector<vector<int>> dp(n, vector<int>(4, -1));
    return solve(points, n - 1, 3, dp);
}

// dp - tabulation
int solve(vector<vector<int>> &points, int n)
{
    vector<vector<int>> dp(n, vector<int>(4, 0));
    dp[0][0] = max(dp[0][1], dp[0][2]);
    dp[0][1] = max(dp[0][0], dp[0][2]);
    dp[0][2] = max(dp[0][0], dp[0][1]);
    dp[0][3] = max(dp[0][0], max(dp[0][1], dp[0][2]));

    for (int i = 0; i < 4; i++)
    {
        for (int prevIndex = 0; prevIndex < 4; prevIndex++)
        {
            if (i != prevIndex)
            {
                int point = points[i][prevTask] + dp[i - 1][prevTask];
            }
        }
    }
    return dp[n - 1][3];
}
int maximumPoints(vector<vector<int>> &points, int n)
{

    return solve(points, 3);
}