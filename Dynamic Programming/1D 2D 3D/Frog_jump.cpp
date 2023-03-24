// recursion
int solve(vector<int> &height, int n, int index)
{
    if (index == 0)
        return 0;

    int right = INT_MAX;
    int left = solve(height, n, index - 1) + abs(height[index] - height[index - 1]);

    if (index > 1)
        right = solve(height, n, index - 2) + abs(height[index] - height[index - 2]);

    return min(left, right);
}
int minimumEnergy(vector<int> &height, int n)
{

    return solve(height, n, n - 1);
}

// dp - memoization
int solveDP(vector<int> &height, int n, int index, vector<int> &dp)
{
    if (index == 0)
        return 0;

    if (dp[index] != -1)
        return dp[index];
    int right = INT_MAX;
    int left = solveDP(height, n, index - 1, dp) + abs(height[index] - height[index - 1]);

    if (index > 1)
        right = solveDP(height, n, index - 2, dp) + abs(height[index] - height[index - 2]);

    dp[index] = min(left, right);
    return dp[index];
}
int minimumEnergy(vector<int> &height, int n)
{
    vector<int> dp(n + 1, -1);
    return solveDP(height, n, n - 1, dp);
}

// dp - tabulation
int minimumEnergy(vector<int> &height, int n)
{

    // create the array of vector of size n+1

    vector<int> dp(n + 1, 0);

    dp[0] = 0;

    for (int i = 1; i < n; i++)
    {
        int left = dp[i - 1] + abs(height[i] - height[i - 1]);

        int right = INT_MAX;
        // if the index is greater than one then only run
        if (i > 1)
        {
            right = dp[i - 2] + abs(height[i] - height[i - 2]);
        }

        dp[i] = min(left, right);
    }

    return dp[n - 1];
}