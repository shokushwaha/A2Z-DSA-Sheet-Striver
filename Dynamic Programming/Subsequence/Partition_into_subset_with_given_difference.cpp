// dp - memoization
int mod = 1e9 + 7;
vector<vector<int>> dp;
int solve(long long target, vector<int> &arr, int pos)
{
    if (pos == arr.size())
        return target == 0;
    if (dp[target][pos] != -1)
        return dp[target][pos];

    int take = 0;
    if (arr[pos] <= target)
        take = solve(target - arr[pos], arr, pos + 1);

    int dontTake = solve(target, arr, pos + 1);
    return dp[target][pos] = ((long long)take + dontTake) % mod;
}

int countPartitions(int n, int d, vector<int> &arr)
{
    long long totalSum = accumulate(begin(arr), end(arr), 0);
    long long remainingSum = totalSum - d;

    if (remainingSum < 0)
        return 0;
    if (remainingSum & 1)
        return 0;

    dp.resize(remainingSum / 2 + 1, vector<int>(n, -1));
    return solve(remainingSum / 2, arr, 0);
}