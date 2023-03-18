// recursion
long long int solve(int coins[], int N, int sum, int ind)
{
    // base case
    if (ind >= N)
        return 0;

    if (sum == 0)
        return 1;

    if (sum < 0)
        return 0;

    // include - subtract from sum and don't move the index as we can take a element any number of times
    int x = solve(coins, N, sum - coins[ind], ind);

    // exclude - do not do anything to sum and increase the index by 1
    int y = solve(coins, N, sum, ind + 1);

    return x + y;
}
long long int count(int coins[], int N, int sum)
{
    // code here.
    return solve(coins, N, sum, 0);
}