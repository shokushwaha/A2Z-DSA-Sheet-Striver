long long trappingWater(int arr[], int n)
{
    int left[n];
    left[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        left[i] = max(arr[i], left[i - 1]);
    }
    int right[n];
    right[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        right[i] = max(arr[i], right[i + 1]);
    }
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += min(left[i], right[i]) - arr[i];
    }

    return sum;
}