// recursion - coming from top to down through the stairs
int solve(int n)
{
    if (n == 0)
        return 1;
    if (n < 0)
        return 0;

    return solve(n - 1) + solve(n - 2);
}

// dp - memoization - coming from top to down throught stairs and storing the value in dp
long long int mod = 1000000007;
long long int dp[mod];

int solveDP(int n)
{
    if (n == 0)
        return 1;
    if (n < 0)
        return 0;

    if (dp[n] != -1)
        return dp[n];

    dp[n] = solveDP(n - 1) % mod + solveDP(n - 2) % mod;
    return dp[n];
}
void nStairs(int n)
{
    for (int i = 0; i < mod; i++)
        dp[i] = -1;

    return solveDP(n);
}
