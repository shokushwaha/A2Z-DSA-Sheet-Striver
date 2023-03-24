// recursion
int solve(int arr[], int n, int index)
{
    // base case
    if (index == 0)
        return arr[0];

    if (index < 0)
        return 0;

    // if we pick one house then we cannot pick house adjacent to it so decreasing the index by 2 and adding the value of that house
    int pick = arr[index] + solve(arr, n, index - 2);

    // not pick the house then we can pick the house at next index so decrease the index by 1
    int notPick = 0 + solve(arr, n, index - 1);

    return max(pick, notPick);
}
int FindMaxSum(int arr[], int n)
{
    return solve(arr, n, n - 1);
}

// dp - memoization
int solveDP(int arr[], int n, int index, vector<int> &dp)
{
    if (index == 0)
        return arr[0];
    if (index < 0)
        return 0;

    if (dp[index] != -1)
        return dp[index];

    int pick = arr[index] + solveDP(arr, n, index - 2, dp);
    int notPick = 0 + solveDP(arr, n, index - 1, dp);

    return dp[index] = max(pick, notPick);
}
int FindMaxSum(int arr[], int n)
{
    vector<int> dp(n + 1, -1);
    return solveDP(arr, n, n - 1, dp);
}

// dp -tabulation
int solveTAB(int arr[], int n)
{
    // 1 :
    vector<int> dp(n + 1, 0);

    // 2 :
    dp[0] = arr[0];
    dp[1] = max(arr[0], arr[1]);
    // 3 :
    for (int i = 1; i, n; i++)
    {
        int pick = arr[i] + dp[i - 2];
        int notPick = 0 + dp[i - 1];
        dp[i] = max(pick, notPick);
    }
    return dp[n - 1];
}
int FindMaxSum(int arr[], int n)
{
    return solveTAB(arr, n);
}