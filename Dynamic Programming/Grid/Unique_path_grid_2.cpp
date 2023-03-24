// recursion
int mod = 1e9 + 7;
int solve(int n, int m, vector<vector<int>> &grid)
{
  // reached the destination return 1
  if (n == 0 && m == 0)
    return 1;

  // out of grid return 0
  if (n < 0 || m < 0)
    return 0;

  // blocked element return 0
  if (n >= 0 && m >= 0 && grid[n][m] == 1)
    return 0;

  // moving up decrease the row by 1
  int up = solve(n - 1, m, grid);

  // moving left decrease the column by 1
  int left = solve(n, m - 1, grid);

  // sum the total paths
  return (up + left) % mod;
}
int totalWays(int n, int m, vector<vector<int>> &grid)
{
  return solve(n - 1, m - 1, grid) % mod;
}

// dp - memoization
int mod = 1e9 + 7;
int solve(int i, int j, vector<vector<int>> &dp, vector<vector<int>> &grid)
{

  if (i >= 0 && j >= 0 && grid[i][j] == 1)
    return 0;

  if (i == 0 && j == 0)
    return 1;

  if (i < 0 || j < 0)
    return 0;

  if (dp[i][j] != -1)
    return dp[i][j];

  int up = solve(i - 1, j, dp, grid);
  int left = solve(i, j - 1, dp, grid);

  return dp[i][j] = (up + left) % mod;
}

int totalWays(int n, int m, vector<vector<int>> &grid)
{
  vector<vector<int>> dp(n, vector<int>(m, -1));
  return solve(n - 1, m - 1, dp, grid) % mod;
}

// dp - tabulation
int mod = 1e9 + 7;
int solve(int n, int m, vector<vector<int>> &grid)
{
  vector<vector<int>> dp(n, vector<int>(m, 0));

  dp[0][0] = 1;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (grid[i][j] == 1)
        dp[i][j] = 0;
      else if (i == 0 && j == 0)
        continue;

      else
      {
        int up = 0;
        if (i > 0)
          up = dp[i - 1][j];
        int left = 0;
        if (j > 0)
          left = dp[i][j - 1];

        dp[i][j] = (up + left) % mod;
      }
    }
  }
  return dp[n - 1][m - 1];
}
int totalWays(int n, int m, vector<vector<int>> &grid)
{
  return solve(n, m, grid) % mod;
}