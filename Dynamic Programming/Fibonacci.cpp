// recursion
int fibonacci(int n)
{
    if (n <= 1)
        return n;

    return fibonacci(n - 1) + fibonacci(n - 2);
}

// memoization
int dp[10000000];
int fibonacci(int n)
{
    if (n <= 1)
        return n;

    if (dp[n] != -1)
        return dp[n];

    dp[n] = fibonacci(n - 1) + fibonacci(n - 2);
    return dp[n];
}

// tabulation
int fibonacci(int n)
{
    // step 1 : initialise dp
    vector<int> dp(n + 1);

    // step 2 : analyze the base condition
    dp[0] = 0;
    dp[1] = 1;

    // step 3 : loop for the given range
    for (int i = 2; i <= n; i++)
        dp[n] = dp[n - 1] + dp[n - 2];

    return dp[n];
}
