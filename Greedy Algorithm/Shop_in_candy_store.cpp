vector<int> candyStore(int candies[], int N, int K)
{
    sort(candies, candies + N);
    int maxi = 0;
    int buy = 0;
    int free = N - 1;

    while (buy <= free)
    {
        maxi += candies[buy];
        buy++;
        free -= K;
    }

    int mini = 0;
    buy = N - 1;
    free = 0;

    while (free <= buy)
    {
        mini += candies[buy];
        buy--;
        free += K;
    }

    vector<int> ans;
    ans.push_back(maxi);
    ans.push_back(mini);

    return ans;
}