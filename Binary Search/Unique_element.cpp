int findOnce(int arr[], int n)
{
    int unique = 0;

    for (int i = 0; i < n; i++)
    {

        unique ^= arr[i];
    }

    return unique;
}