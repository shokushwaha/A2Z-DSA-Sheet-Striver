// recursion
int solve(int n, vector<vector<int>> &triangle, int i, int j)
{
    // base case we reach the last row return triangle[last_row][column_number]
    if (i == n - 1)
        return triangle[n - 1][j];

    // out of grid
    else if (i > n - 1)
        return 1e9;

    // moving down by increasing row by 1
    int down = triangle[i][j] + solve(n, triangle, i + 1, j);
    // moving diagonal by increasing row by 1 and column by 1
    int diagonal = triangle[i][j] + solve(n, triangle, i + 1, j + 1);

    // minimum of both the ways
    return min(down, diagonal);
}
int minimizeSum(int n, vector<vector<int>> &triangle)
{

    return solve(n, triangle, 0, 0);
}

// dp - memoization
int solve(int n, vector<vector<int>> &triangle, int i, int j, vector<vector<int>> &dp)
{
    if (i == n - 1)
        return triangle[n - 1][j];

    else if (i > n - 1)
        return 1e9;

    else if (dp[i][j] != -1)
        return dp[i][j];

    int down = triangle[i][j] + solve(n, triangle, i + 1, j, dp);
    int diagonal = triangle[i][j] + solve(n, triangle, i + 1, j + 1, dp);

    return dp[i][j] = min(down, diagonal);
}
int minimizeSum(int n, vector<vector<int>> &triangle)
{
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return solve(n, triangle, 0, 0, dp);
}

// dp - tabulation
int solve(vector<vector<int>> &triangle)
{
    int n = triangle.size();
    // step 1 : initialsie dp
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // step 2 : analyze base cases
    for (int j = 0; j < n; j++)
        dp[n - 1][j] = triangle[n - 1][j];

    // step 3 : loop for the range n-1 to 0
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = i; j >= 0; j--)
        {
            int up = triangle[i][j] + dp[i + 1][j];
            int diagonal = triangle[i][j] + dp[i + 1][j + 1];
            dp[i][j] = min(up, diagonal);
        }
    }

    return dp[0][0];
}
int minimumTotal(vector<vector<int>> &triangle)
{
    return solve(triangle);
}