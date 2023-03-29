int f(int index, int W, int val[], int wt[], vector<vector<int>> &dp)
{
    if (index == 0)
    {
        if (wt[index] <= W)
            return (W / wt[index]) * val[index];

        else
            return 0;
    }

    if (dp[index][W] != -1)
        return dp[index][W];

    int take = INT_MIN;
    if (wt[index] <= W)
        take = val[index] + f(index, W - wt[index], val, wt, dp);

    int notTake = f(index - 1, W, val, wt, dp);

    return dp[index][W] = max(take, notTake);
}
int knapSack(int N, int W, int val[], int wt[])
{
    vector<vector<int>> dp(N, vector<int>(W + 1, -1));
    return f(N - 1, W, val, wt, dp);
}