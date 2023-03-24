// recursion
int solve(vector<int> &num, int tar, int n, int ind)
{
    if (tar == 0)
        return 1;

    if (ind == 0)
        return tar == num[0];

    int take = 0;
    if (num[ind] <= tar)
        take = solve(num, tar - num[ind], n, ind - 1);

    int notTake = solve(num, tar, n, ind - 1);

    return take + notTake;
}
int findWays(vector<int> &num, int tar)
{
    int n = num.size();
    return solve(num, tar, n, n - 1);
}

// dp - memoization
int solve(vector<int> &num, int tar, int n, int ind, vector<vector<int>> &dp)
{
    if (tar == 0)
        return 1;

    if (ind == 0)
        return tar == num[0];

    if (dp[ind][tar] != -1)
        return dp[ind][tar];
    int take = 0;
    if (num[ind] <= tar)
        take = solve(num, tar - num[ind], n, ind - 1, dp);

    int notTake = solve(num, tar, n, ind - 1, dp);

    return dp[ind][tar] = take + notTake;
}
int findWays(vector<int> &num, int tar)
{
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(tar + 1, -1));
    return solve(num, tar, n, n - 1, dp);
}

// dp - tabulation
int solve(vector<int> &arr, int sum)
{
    int n = arr.size();

    vector<vector<int>> dp(n, vector<int>(sum + 1, 0));
    for (int i = 0; i < n; i++)
        dp[i][0] = 1;

    if (arr[0] <= sum)
        dp[0][arr[0]] = 1;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            int notTake = dp[i - 1][j];
            int take = 0;
            if (arr[i] <= sum)
                take = dp[i - 1][j - arr[i]];
            dp[i][j] = take + notTake;
        }
    }
    return dp[n - 1][sum];
}
int findWays(vector<int> &num, int tar)
{
    return solve(num, tar);
}