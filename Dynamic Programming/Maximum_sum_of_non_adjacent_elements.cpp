// recursion
int solve(int *arr, int n, int ind)
{
    // base case
    if (ind == 0)
        return arr[0];

    if (ind < 0)
        return 0;

    // including element at a index and adding it in the total value
    int incl = solve(arr, n, ind - 2) + arr[ind];

    // excluding element at a index and not adding it in the total value
    int excl = solve(arr, n, ind - 1);

    // returning max of the two conditions
    return max(incl, excl);
}
int findMaxSum(int *arr, int n)
{
    return solve(arr, n, n - 1);
}

//************************************************************************************************

// dp - memoization
int solveDP(int *arr, int n, int ind, vector<int> &dp)
{
    if (ind == 0)
        return arr[0];

    if (ind < 0)
        return 0;

    if (dp[ind] != -1)
        return dp[ind];

    int incl = solveDP(arr, n, ind - 2, dp) + arr[ind];
    int excl = solveDP(arr, n, ind - 1, dp);

    dp[n] = max(incl, excl);
    return dp[n];
}
int findMaxSum(int *arr, int n)
{
    vector<int> dp(n + 1, -1);
    return solveDP(arr, n, n - 1, dp);
}

//************************************************************************************************

// dp - tabulation
int solveTAB(int *arr, int n)
{
    // step 1 : initialise dp array
    vector<int> dp(n, 0);

    // step 2 : analyze the base case
    dp[0] = arr[0];

    // step 3 : loop for the range
    for (int i = 1; i < n; i++)
    {
        int incl = dp[i - 2] + arr[i];
        int excl = dp[i - 1];

        dp[i] = max(incl, excl);
    }

    return dp[n - 1];
}
int findMaxSum(int *arr, int n)
{
    if (n == 1)
        return arr[0];
    return solveTAB(arr, n);
}