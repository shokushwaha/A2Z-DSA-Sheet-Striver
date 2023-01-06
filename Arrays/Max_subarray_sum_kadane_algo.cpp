int maxSum(int arr[], int n)
{
    int currSum = 0;
    int maxS = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        currSum += arr[i];
        if (maxS < currSum)
            maxS = currSum;
        if (currSum < 0)
            currSum = 0;
    }
    return maxS;
}