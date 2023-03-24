// recrusion
int solve(int w[], int val[], int W, int index)
{
    if (index == 0)
    {
        if (w[index] <= W)
            return val[index];
        else
            return 0;
    }

    int take = INT_MIN;
    if (w[index] <= W)
        take = val[index] + solve(w, val, W - w[index], index - 1);

    int notTake = solve(w, val, W, index - 1);

    return max(take, notTake);
}
int knapsack(int weight[], int val[], int maxWeight, int n)
{
    return solve(weight, val, maxWeight, n - 1);
}

// dp - memoization
int solve(int w[], int val[], int W, int index, vector<vector<int>> &dp)
{
    if (index == 0)
    {
        if (w[index] <= W)
            return val[index];
        else
            return 0;
    }

    if (dp[index][W] != -1)
        return dp[index][W];

    int take = INT_MIN;
    if (w[index] <= W)
        take = val[index] + solve(w, val, W - w[index], index - 1, dp);

    int notTake = solve(w, val, W, index - 1, dp);

    return dp[index][W] = max(take, notTake);
}
int knapsack(int weight[], int val[], int maxWeight, int n)
{
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));
    return solve(weight, val, maxWeight, n - 1, dp);
}
