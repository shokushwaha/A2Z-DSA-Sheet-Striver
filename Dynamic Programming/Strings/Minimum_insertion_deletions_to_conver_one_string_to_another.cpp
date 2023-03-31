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
int minOperations(string str1, string str2)
{

    return (str1.size() + str2.size() - 2 * lcs(str1.size(), str2.size(), str1, str2));
}