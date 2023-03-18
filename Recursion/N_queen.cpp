// put queen in one column and check for the other columns
void addSolution(vector<vector<int>> &board, vector<vector<int>> &ans, int n)
{
    vector<int> temp;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            temp.push_back([i][j]);
    }

    ans.push_back(temp);
}
bool isSafe(int row, int col, vector<vector<int>> &board, int n)
{
    // safe - not in same row , not in same column , not in diagonal
    // we are putting only one queen in one column so no need to check for second condition

    // same row check
    while (row >= 0)
    {
        if (board[row][col] == 1)
            return false;

        row--;
    }

    // upper diagonal on left side
    while (row >= 0 && col >= 0)
    {
        if (board[row][col] == 1)
            return false;

        row--;
        col--;
    }

    // lower diagonal on right side
    while (row < n && col >= 0)
    {
        if (board[row][col] == 1)
            return false;

        row++;
        col--;
    }
}
void solve(vector<vector<int>> &board, vector<vector<int>> &ans, int n, int col)
{
    // base case - all columns are filled
    if (col == n)
    {
        addSolution(board, ans, n);
        return;
    }

    for (int row = 0; row < n; row++)
    {
        if (isSafe(row, col, board, n))
        {

            // if it is safe - put queen on board
            board[row][col] = 1;

            // call for next column
            solve(board, ans, n, col + 1);

            // backtrack
            board[row][col] = 0;
        }
    }
}
vector<vector<int>> nQueens(int n)
{
    // creating board
    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<vector<int>> ans;

    solve(board, ans, n, 0);

    return ans;
}