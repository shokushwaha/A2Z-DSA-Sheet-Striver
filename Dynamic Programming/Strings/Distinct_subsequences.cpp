// recursion
int f(int i, int j, string s, string t)
{
    if (j < 0)
        return 1;

    if (i < 0 && j > 0)
        return 0;

    // last character matches
    if (s[i] == t[j])
        return dp[i][j] = f(i - 1, j - 1, s, t) + f(i - 1, j, s, t);

    // last character does not matches
    else if (s[i] != t[j])
        return dp[i][j] = f(i - 1, j, s, t);
}
int numDistinct(string s, string t)
{
    int n = s.size();
    int m = t.size();

    return f(n - 1, m - 1, s, t);
}

// dp - memoization
int f(int i, int j, string s, string t, vector<vector<int>> &dp)
{
    if (j < 0)
        return 1;

    if (i < 0 && j > 0)
        return 0;

    // last character matches

        if(dp[i][j!=-1)
            return dp[i][j];

        if (s[i] == t[j])
            return dp[i][j] = f(i - 1, j - 1, s, t, dp) + f(i - 1, j, s, t, dp);

        // last character does not matches
        else if (s[i] != t[j])
            return dp[i][j] = f(i - 1, j, s, t, dp);
}
int numDistinct(string s, string t)
{
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(n - 1, m - 1, s, t, dp);
}