// recursion
bool solve(int ind1, int ind2, string &s, string &p)
{
    if (ind1 < 0 && ind2 < 0)
        return true;
    if (ind2 < 0)
        return false;
    if (ind1 < 0)
    {
        for (int i = 0; i <= ind2; i++)
        {
            if (p[i] != '*')
                return false;
        }
        return true;
    }

    if (s[ind1] == p[ind2] || p[ind2] == '?')
        return solve(ind1 - 1, ind2 - 1, s, p);
    else if (p[ind2] == '*')
    {
        return solve(ind1 - 1, ind2, s, p) || solve(ind1, ind2 - 1, s, p);
    }
    return false;
}
bool isMatch(string s, string p)
{
    int n = s.length();
    int m = p.length();

    return solve(n - 1, m - 1, s, p);
}

// dp - memoization
bool solve(int ind1, int ind2, string &s, string &p, vector<vector<int>> &dp)
{
    if (ind1 < 0 && ind2 < 0)
        return true;
    if (ind2 < 0)
        return false;
    if (ind1 < 0)
    {
        for (int i = 0; i <= ind2; i++)
        {
            if (p[i] != '*')
                return false;
        }
        return true;
    }
    if (dp[ind1][ind2] != -1)
        return dp[ind1][ind2];
    if (s[ind1] == p[ind2] || p[ind2] == '?')
        return dp[ind1][ind2] = solve(ind1 - 1, ind2 - 1, s, p, dp);
    else if (p[ind2] == '*')
    {
        return dp[ind1][ind2] = solve(ind1 - 1, ind2, s, p, dp) || solve(ind1, ind2 - 1, s, p, dp);
    }
    return dp[ind1][ind2] = false;
}
bool isMatch(string s, string p)
{
    int n = s.length();
    int m = p.length();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return solve(n - 1, m - 1, s, p, dp);
}

// dp - tabulation

bool isMatch(string s, string p)
{
    int m = s.length();
    int n = p.length();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int j = 1; j <= n; j++)
    {
        int k;
        for (k = 1; k <= j; k++)
        {
            if (p[k - 1] != '*')
                break;
        }
        if (k == j + 1)
            dp[0][j] = 1;
    }
    dp[0][0] = 1;

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
                dp[i][j] = dp[i - 1][j - 1];
            else if (p[j - 1] == '*')
            {
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
            }
            else
                dp[i][j] = 0;
        }
    }

    return dp[m][n];
}
