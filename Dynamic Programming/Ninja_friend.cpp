// dp - memoization
// allowed movements are down,leftDiagona,rightDiagonal
int f(int row, int col1, int col2, vector<vector<int>> &grid, int n, int m, vector<vector<vector<int>>> &dp)
{
    // out of grid
    if (col1 >= m || col1 < 0 || col2 >= m || col2 < 0)
        return -1e9;

    // reached the last row
    if (row == n - 1)
    {
        // if col1 and col2 are same return that cell
        if (col1 == col2)
            return grid[row][col1];

        // if col1 and col2 are not same return sum of both cells
        else
            return (grid[row][col1] + grid[row][col2]);
    }

    if (dp[row][col1][col2] != -1)
        return dp[row][col1][col2];

    // we have to make 9 function calls as on every step we have 9 different combinations
    int dy[] = {-1, 0, 1};

    int maxi = INT_MIN;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int ans;
            // if both the columns are same take that cell and call for other movements
            if (col1 == col2)
                ans = grid[row][col1] + f(row + 1, col1 + dy[i], col2 + dy[j], grid, n, m, dp);

            // if both the columns are not same take sum of both the cells and call for other movements
            else
                ans = grid[row][col1] + grid[row][col2] + f(row + 1, col1 + dy[i], col2 + dy[j], grid, n, m, dp);

            maxi = max(maxi, ans);
        }
    }

    return dp[row][col1][col2] = maxi;
}

int solve(int n, int m, vector<vector<int>> &grid)
{
    // code here
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
    return f(0, 0, m - 1, grid, n, m, dp);
}