// recrusion
int solve(vector<int> &height, int n, int index, int k)
{
    if (index == 0)
        return 0;
    int minEnergy = INT_MAX;
    for (int i = 1; i <= k; i++)
    {
        if (index - i >= 0)
            int jumpEnergy = solve(height, n, index - i, k) + abs(height[index] - height[index - i]);
        minEnergy = min(jumpEnergy, minEnergy);
    }
    return minEnergy;
}
int minimumEnergy(vector<int> &height, int n, int k)
{
    return solve(height, n, n - 1, k);
}

// dp - memoization
int solve(vector<int> &height, int n, int index, int k, vector<int> &dp)
{
    if (index == 0)
        return 0;
    int minEnergy = INT_MAX;

    if (dp[index] != -1)
        return dp[index];
    for (int i = 1; i <= k; i++)
    {
        if (index - i >= 0)
            int jumpEnergy = solve(height, n, index - i, k, dp) + abs(height[index] - height[index - i]);
        minEnergy = min(jumpEnergy, minEnergy);
    }
    return dp[index] = minEnergy;
}
int minimumEnergy(vector<int> &height, int n, int k)
{
    vector<int> dp(n, -1);
    return solve(height, n, n - 1, k);
}