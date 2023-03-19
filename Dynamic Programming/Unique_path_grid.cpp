// recursion
int solve(int a, int b)
{

    // base cases
    if (a == 0 && b == 0)
        return 1;
    if (a < 0 || b < 0)
        return 0;

    // moving up and decrease the row by 1
    int up = solve(a - 1, b);

    // moving left and decrease the column by 1
    int left = solve(a, b - 1);

    // total number of paths
    return up + left;
}

int NumberOfPath(int a, int b)
{
    return solve(a - 1, b - 1);
}

// dp - memoization
int solve(int a, int b, vector<vector<int>> &dp)
{
    if (a == 0 && b == 0)
        return 1;
    if (a < 0 || b < 0)
        return 0;

    if (dp[a][b] != -1)
        return dp[a][b];

    int up = solve(a - 1, b, dp);
    int left = solve(a, b - 1, dp);

    return dp[a][b] = up + left;
}

int NumberOfPath(int a, int b)
{
    vector<vector<int>> dp(a, vector<int>(b, -1));
    return solve(a - 1, b - 1, dp);
}

// dp - tabulation
int solve(int a, int b)
{

    vector<vector<int>> dp(a, vector<int>(b, 0));
    dp[0][0] = 1;
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            if (i == 0 && j == 0)
                continue;
            int up = 0;
            if (i > 0)
                up = dp[i - 1][j];
            int left = 0;
            if (j > 0)
                left = dp[i][j - 1];

            dp[i][j] = up + left;
        }
    }
    return dp[a - 1][b - 1];
}
int NumberOfPath(int a, int b)
{
    return solve(a, b);
}