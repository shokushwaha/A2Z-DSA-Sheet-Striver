// recursion
int solve(vector<int> &cost, int n)
{
    if (n == 0)
        return cost[0];

    if (n == 1)
        return cost[1];

    // adding the cost of that stair as in the next step we have to go through that stair
    return cost[n] + min(solve(cost, n - 1), solve(cost, n - 2));
}
int minCostClimbingStairs(vector<int> &cost, int n)
{

    // we are on the target floor and finding the minimum cost from the last two stairs
    return min(solve(cost, n - 1), solve(cost, n - 2));
}

// ************************************************************************************************

// dp - memoization
int solveDP(vector<int> &cost, int n, vector<int> &dp)
{
    if (n == 0)
        return cost[0];

    if (n == 1)
        return cost[1];

    if (dp[n] != -1)
        return dp[n];

    // adding the cost of that stair as in the next step we have to go through that stair
    dp[n] = cost[n] + min(solveDP(cost, n - 1, dp), solveDP(cost, n - 2, dp));

    return dp[n];
}
int minCostClimbingStairs(vector<int> &cost, int n)
{
    vector<int> dp(1001, -1);

    // we are on the target floor and finding the minimum cost from the last two stairs
    return min(solveDP(cost, n - 1, dp), solveDP(cost, n - 2, dp));
}

// ************************************************************************************************

// dp - tabulation
int solveDPTab(vector<int> &cost, int n)
{
    // step 1 : initialise dp array
    vector<int> dp(n + 1);

    // step 2 : initialise base conditions
    dp[0] = cost[0];
    dp[1] = cost[1];

    // step 3 : loop for the given range
    for (int i = 2; i <= n; i++)
        dp[i] = cost[i] + min(dp[i - 1] + dp[i - 2]);

    return dp[n];
}