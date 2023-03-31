int longest_substring(string s1, string s2)
{
    int a = s1.size();
    int b = s2.size();

    int ans = 0;
    int dp[a + 1][b + 1];

    for (int i = 0; i <= a; i++)
        dp[i][0] = 0;

    for (int i = 0; i <= b; i++)
        dp[0][i] = 0;

    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= b; j++)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                ans = max(ans, dp[i][j]);
            }
        }
        else
        {
            dp[i][j] = 0;
        }
    }

    return ans;
}