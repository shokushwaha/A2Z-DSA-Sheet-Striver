int findMin(int arr[], int n)
{

    int ans = INT_MAX;
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[low] <= arr[mid])
        {
            ans = min(arr[low], ans);
            low = mid + 1;
        }
        else
        {
            ans = min(arr[mid], ans);
            high = mid - 1;
        }
    }
    return ans;
}