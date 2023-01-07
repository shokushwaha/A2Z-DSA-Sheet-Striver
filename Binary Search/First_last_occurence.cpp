int LeftBinarySearch(int arr[], int n, int x)
{
    int low = 0;
    int high = n - 1;
    int result = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == x)
        {
            result = mid;
            high = mid - 1;
        }
        else if (arr[mid] < x)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return result;
}
int RightBinarySearch(int arr[], int n, int x)
{
    int low = 0;
    int high = n - 1;
    int result = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == x)
        {
            result = mid;
            low = mid + 1;
        }
        else if (arr[mid] < x)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return result;
}

vector<int> find(int arr[], int n, int x)
{
    vector<int> v;
    int l = LeftBinarySearch(arr, n, x);
    int r = RightBinarySearch(arr, n, x);
    v = {l, r};
    return v;
}