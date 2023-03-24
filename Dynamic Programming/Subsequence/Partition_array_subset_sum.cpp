// recursion
bool solve(vector<int> &nums, int target, int index)
{
    if (index == 0)
        return target == 0;

    if (target == 0)
        return true;

    if (index < 0)
        return false;

    bool take = false;
    if (nums[index] <= target)
        take = solve(nums, target - nums[index], index - 1);

    bool notTake = solve(nums, target, index - 1);

    return take || notTake;
}
bool canPartition(vector<int> &nums)
{
    int sum = 0;
    int n = nums.size();
    for (int i = 0; i < nums.size(); i++)
        sum += nums[i];

    if (sum & 1)
        return false;

    else
        return solve(nums, sum / 2, nums.size() - 1);
}

// dp - memoization
bool solve(vector<int> &nums, int target, int index, vector<vector<int>> &dp)
{
    if (index == 0)
        return target == 0;

    if (target == 0)
        return true;

    if (index < 0)
        return false;

    if (dp[index][target] != -1)
        return dp[index][target];

    bool take = false;
    if (nums[index] <= target)
        take = solve(nums, target - nums[index], index - 1, dp);

    bool notTake = solve(nums, target, index - 1, dp);

    return dp[index][target] = take || notTake;
}
bool canPartition(vector<int> &nums)
{
    int sum = 0;
    int n = nums.size();
    for (int i = 0; i < nums.size(); i++)
        sum += nums[i];

    vector<vector<int>> dp(n, vector<int>(sum / 2 + 1, -1));
    if (sum & 1)
        return false;

    else
        return solve(nums, sum / 2, nums.size() - 1, dp);
}