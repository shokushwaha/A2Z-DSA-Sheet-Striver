void solve(int i, int j, vector < vector >> &a, int n, vector<string> &ans, string move, vector<vector<int>> &vis, int di[], int dy[])
{
    // base case - reached the end of the maze
    if (i == n - 1 && j == n - 1)
    {
        ans.push_back(move);
        return;
    }

    // lexiographical order
    // only 4 directions possible - suppose we are at i,j
    //     down - i-1,j
    //     left - i,j-1
    //     right - i,j+1
    //     up - i+1,j
    string dir = "DLRU";
    for (int ind = 0; ind < 4; ind++)
    {
        int nexti = i + di[ind];
        int nextj = j + dy[ind];

        // doing all the boundary checks + checking the next element is not visited as we can traverse one element at max once + the next element should be open for traversal ie it should not be blocked
        if (nexti >= 0 && nexti < n && nextj >= 0 && nextj < n && !vis[nexti][nextj] && a[nexti][nextj] == 1)
        {
            // marking the current box = 1
            vis[i][j] = 1;

            // calling for next block in the dlru order
            solve(nexti, nextj, a, n, ans, move + dir[ind], vis, di, dj);

            // marking the current box = 0 if path not found in the current iteration
            vis[i][j] = 0;
        }
    }
}
vector<string> findPath(vector<vector<int>> &m, int n)
{
    vector<string> ans;
    vector<vector<int>> vis(n, 0);

    // storing addition/subtraction for every direction down left right up
    int di[] = {-1, 0, 0, 1};
    int dy = {0, -1, 1, 0};

    // starting box should be open to enter the maze
    if (m[0][0] == 1)
        solve(0, 0, m, n, ans, "", vis, di, dy);

    return ans;
}