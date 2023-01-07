pair<int, int> getFloorAndCeil(int arr[], int n, int x)
{

    int c = -1;

    int f = -1;

    pair<int, int> p;

    sort(arr, arr + n);

    int high = n - 1;

    int low = 0;

    while (low <= high)
    {

        int mid = (low + high) / 2;

        if (arr[mid] == x)
        {

            c = arr[mid];

            f = arr[mid];

            break;
        }
        else if (arr[mid] < x)
        {

            f = arr[mid];

            low = mid + 1;
        }
        else
        {

            c = arr[mid];

            high = mid - 1;
        }
    }

    p = {f, c};

    return p;
}