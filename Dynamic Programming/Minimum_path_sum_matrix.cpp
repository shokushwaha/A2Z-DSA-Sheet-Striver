// recursion
int solve(vector<vector<int>> &arr, int i, int j, int n)
{

    if (j < 0 || j >= n)
        return 1e5;

    else if (i == 0)
        return arr[0][j];

    int up = solve(arr, i - 1, j, n);
    int upLeft = solve(arr, i - 1, j - 1, n);
    int upRight = solve(arr, i - 1, j + 1, n);

    return arr[i][j] + min(up, min(upLeft, upRight));
}
int minFallingPathSum(vector<vector<int>> &A)
{
    int n = A.size();
    return solve(A, n - 1, n - 1, n);
}

// dp - memoization
int rec(int i, int j, vector<vector<int>> &mat, vector<vector<int>> &dp)
{

    // Base Case
    if (j < 0 || j >= mat.size())
        return 1e5;
    if (i == 0)
        return mat[0][j];

    // memoization
    if (dp[i][j] != -1)
        return dp[i][j];

    // Explore all the paths
    int up = mat[i][j] + rec(i - 1, j, mat, dp);
    int leftDiag = mat[i][j] + rec(i - 1, j - 1, mat, dp);
    int rightDiag = mat[i][j] + rec(i - 1, j + 1, mat, dp);

    // take the minimum
    return dp[i][j] = min(up, min(leftDiag, rightDiag));
}
int minFallingPathSum(vector<vector<int>> &A)
{
    int n = A.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return rec(n - 1, n - 1, A, dp);
}

// dp - tabulation
int solve(vector<vector<int>> &A, int n)
{
    // step 1 : initialise dp
    int dp[n][n] = {0};

    // step 2 : analyze the base case
    for (int j = 0; j < n; j++)
        dp[0][j] = A[0][j];

    // step 3 : loop for the range
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int up = A[i][j] + dp[i - 1][j];
            int upLeft = upRight = 1e5;
            if (j - 1 >= 0)
                upLeft = A[i][j] + dp[i - 1][j - 1];
            if (j + 1 < n)
                upRight = A[i][j] + dp[i - 1][j + 1];

            dp[i][j] = min(up, min(upLeft, upRight));
        }
    }
    return dp[n - 1][n - 1];
}
int minFallingPathSum(vector<vector<int>> &A)
{
    int n = A.size();
    return solve(A, n);
}