int findFloor(vector<long long> v, long long n, long long x)
{

    // Your code here
    int index = -1;
    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (v[mid] == x)
        {
            index = mid;
            break;
        }
        else if (v[mid] < x)
        {
            index = mid;
            low = mid + 1;
        }
        else if (v[mid] > x)
        {
            high = mid - 1;
        }
    }
    return index;
}