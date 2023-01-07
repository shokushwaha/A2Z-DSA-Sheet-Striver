int searchInsertK(vector<int> arr, int N, int k)
{
    int low = 0;

    int high = N - 1;

    int ans = 0;

    if (arr[0] > k)
        return 0;

    if (arr[N - 1] < k)
        return N;

    while (low <= high)
    {

        int mid = (low + high) / 2;

        if (arr[mid] == k)

        {

            return mid;
        }

        else if (arr[mid] < k)
        {

            low = mid + 1;
        }

        else
        {

            high = mid - 1;
        }
    }

    return low;
}