// recursion
int solve(int ind1, int ind2, string str1, string str2)
{
    if (ind1 < 0 || ind2 < 0)
        return 0;

    // character matches -> length of substring increases by 1
    if (str1[ind1] == str2[ind2])
        return 1 + solve(ind1 - 1, ind2 - 1, str1, str2);

    // character does not matches -> explore both possibilities
    return max(solve(ind1 - 1, ind2, str1, str2), solve(ind1, ind2 - 1, str1, str2));
}
int getLengthOfLCS(string &str1, string &str2)
{
    int a = str1.size();
    int b = str2.size();
    return solve(a - 1, b - 1, str1, str2);
}

// dp - memoization
int solve(int ind1, int ind2, string str1, string str2, vector<vector<int>> &dp)
{
    if (ind1 < 0 || ind2 < 0)
        return 0;

    if (dp[ind1][ind2] != -1)
        return dp[ind1][ind2];
    if (str1[ind1] == str2[ind2])
        dp[ind1][ind2] = 1 + solve(ind1 - 1, ind2 - 1, str1, str2, dp);

    else
        dp[ind1][ind2] = max(solve(ind1 - 1, ind2, str1, str2, dp), solve(ind1, ind2 - 1, str1, str2, dp));

    return dp[ind1][ind2];
}
int getLengthOfLCS(string &str1, string &str2)
{

    int a = str1.size();
    int b = str2.size();
    vector<vector<int>> dp(a, vector<int>(b, -1));

    return solve(a - 1, b - 1, str1, str2, dp);
}

// dp - tabulation
int lcs(int x, int y, string s1, string s2)
{
    int a = s1.size();
    int b = s2.size();

    int dp[a + 1][b + 1];

    for (int i = 0; i <= a; i++)
        dp[i][0] = 0;

    for (int i = 0; i <= b; i++)
        dp[0][i] = 0;

    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= b; j++)
        {
            dp[i][j] = 0;
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[a][b];
}