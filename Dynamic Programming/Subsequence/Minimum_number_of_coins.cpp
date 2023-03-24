// we have to find minimum number of coins we need to take to reach the given target with infinite number of denomiantions

// recursion
int solve(vector<int> &arr, int tar, int index)
{
    if (index == 0)
    {
        if (tar % arr[i] == 0)
            return tar / arr[i];
        else
            return INT_MAX;
    }

    int take = 1 + solve(arr, tar - arr[index], index);
    int notTake = solve(arr, tar, index - 1);
    return min(take, notTake);
}
int coinChange(vector<int> arr, int target)
{
    int n = arr.size();
    return solve(arr, target, n - 1);
}

// dp - memoization
int solve(vector<int> &arr, int tar, int index, vector<vector<int>> &dp)
{
    if (index == 0)
    {
        if (tar % arr[0] == 0)
            return tar / arr[0];
        else
            return INT_MAX;
    }

    if (dp[index][tar] != -1)
        return dp[index][tar];
    int take = 1 + solve(arr, tar - arr[index], index, dp);
    int notTake = solve(arr, tar, index - 1, dp);
    return dp[index][tar] = min(take, notTake);
}
int coinChange(vector<int> arr, int target)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(target + 1, -1));
    return solve(arr, target, n - 1, dp);
}