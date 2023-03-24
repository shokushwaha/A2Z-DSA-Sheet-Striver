// recursion
int solve(vector<vector<int>> &grid, int i, int j)
{

    // reach destination return the value of element
    if (i == 0 && j == 0)
        return grid[0][0];

    // reach out of grid return a maximum value so that when we take minimum it automatically gets rejected
    if (i < 0 || j < 0)
        return 1e9;

    // adding the current element and moving up by decreasing row by 1
    int up = grid[i][j] + solve(grid, i - 1, j);

    // adding the current element and moving left by decreasing column by 1
    int left = grid[i][j] + solve(grid, i, j - 1);

    // minimum of up and left
    return min(up, left);
}
int minimumCostPath(vector<vector<int>> &grid)
{
    int n = grid.size();
    return solve(grid, n - 1, n - 1);
}

// dp - memoization
int solve(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &dp)
{
    if (i == 0 && j == 0)
        return grid[0][0];

    if (i < 0 || j < 0)
        return 1e9;

    if (dp[i][j] != -1)
        return dp[i][j];
    int up = grid[i][j] + solve(grid, i - 1, j, dp);
    int left = grid[i][j] + solve(grid, i, j - 1, dp);

    return dp[i][j] = min(up, left);
}
int minimumCostPath(vector<vector<int>> &grid)
{
    int n = grid.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return solve(grid, n - 1, n - 1, dp);
}