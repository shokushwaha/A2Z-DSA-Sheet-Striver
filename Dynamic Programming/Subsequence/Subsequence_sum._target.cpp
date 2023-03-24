// recursion
bool solve(vector<int> &arr, int target, int index)
{
    // target becomes 0 then return true
    if (target == 0)
        return true;

    // if index becomes 0 and target is 0 return true
    if (index == 0)
        return target == 0;

    // if index goes out of bound return false
    else if (index < 0)
        return false;

    bool take = false, notTake = false;

    // if current element is less than or equal to target then take it and decrease the index
    if (arr[index] <= target)
        take = solve(arr, target - arr[index], index - 1);

    // not taking the element at index
    notTake = solve(arr, target, index - 1);

    // if any of the case returns true then return true
    return take || notTake;
}
bool isSubsetSum(vector<int> arr, int sum)
{
    return solve(arr, sum, arr.size() - 1);
}

// dp - memoization
bool healer(vector<int> arr, int n, int sum, vector<vector<int>> &dp)
{
    if (sum == 0)
        return true;

    if (n == 0)
        return sum == 0;

    if (dp[n][sum] != -1)
        return dp[n - 1][sum];

    // if smaller then we have two choices whether to take it or not
    if (arr[n] <= sum)
        return dp[n - 1][sum] = healer(arr, n - 1, sum - arr[n - 1], dp) || healer(arr, n - 1, sum, dp);

    // if it is bigger than we have to leave it
    else if (arr[n] > sum)
        return dp[n][sum] = healer(arr, n - 1, sum, dp);
}
bool isSubsetSum(vector<int> arr, int sum)
{
    int n = arr.size() - 1;
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
    return healer(arr, n, sum, dp);
}

// dp - tabulation
bool solve(vector<int> &arr, int sum)
{
    int n = arr.size();

    // step 1 : initialize dp
    bool dp[n + 1][sum + 1];

    // step 2 : analyze base cases - if target becomes zero for any index then mark it as true and if index becomes zero then mark it as false
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (i == 0)
                dp[i][j] = false;
            if (j == 0)
                dp[i][j] = true;
        }
    }

    // step 3 : loop for the range
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (arr[i - 1] <= sum)
                dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
            else
                dp[i][j] = arr[i - 1][j];
        }
    }
    return dp[n][sum];
}
bool isSubsetSum(vector<int> arr, int sum)
{
    return solve(arr, sum);
}