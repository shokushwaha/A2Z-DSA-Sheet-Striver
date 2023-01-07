int binarysearch(int arr[], int n, int k)
{
    int s = 0;

    int e = n;

    while (s <= e)
    {

        int m = (s + e) / 2;

        if (arr[m] == k)
        {

            return m;
        }

        else if (arr[m] < k)
        {

            s = m + 1;
        }

        else
        {

            e = m - 1;
        }
    }

    return -1;
}