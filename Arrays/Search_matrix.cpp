int matSearch(vector<vector<int>> &mat, int N, int M, int X)
{

    int i = 0, j = M - 1;
    while (i >= 0 && j >= 0 && i < N && j < M)
    {
        if (mat[i][j] == X)
            return 1;

        else if (mat[i][j] < X)
            i = i + 1;

        else
            j = j - 1;
    }
    return 0;
}