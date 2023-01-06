vector<int> leaders(int a[], int n)
{

    vector<int> ans;

    int maxSoFar = INT_MIN;

    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] >= maxSoFar)
            ans.push_back(a[i]);
        maxSoFar = max(maxSoFar, a[i]);
    }
    reverse(ans.begin(), ans.end());

    return ans;
}