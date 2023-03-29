// recursion
int solve(int price[], int n, int index)
{
    if (index == 0)
        return n * price[0];

    int take = INT_MIN;

    int rodLength = index + 1;
    if (rodLength <= n)
        take = price[index] + solve(price, n - rodLength, index);

    int notTake = solve(price, n, index - 1);

    return max(take, notTake);
}

int cutRod(int price[], int n)
{
    return solve(price, n, n - 1);
}

// dp - memoization
int solve(int price[], int n, int index, vector<vector<int>> &dp)
{
    if (index == 0)
        return n * price[0];

    if (dp[index][n] != -1)
        return dp[index][n];

    int take = INT_MIN;

    int rodLength = index + 1;
    if (rodLength <= n)
        take = price[index] + solve(price, n - rodLength, index, dp);

    int notTake = solve(price, n, index - 1, dp);

    return dp[index][n] = max(take, notTake);
}

int cutRod(int price[], int n)
{
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return solve(price, n, n - 1, dp);
}