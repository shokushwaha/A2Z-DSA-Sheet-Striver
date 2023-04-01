// print any one lcs if there are more than one of same size
string lcs(string s1, string s2)
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
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    // now we will trace the lca starting from dp[a-1][b-1]
    int i = a;
    int j = b;
    string str = "";

    while (i > 0 && j > 0)
    {
        if (str1[i - 1] == str2[j - 1])
        {
            str += str1[i - 1];
            i--;
            j--;
        }
        else
        {
            if (dp1[i - 1] > dp[j - 1])
                i--;
            else
                j--;
        }
    }

    reverse(str.begin(), str.end());

    return str;
}
