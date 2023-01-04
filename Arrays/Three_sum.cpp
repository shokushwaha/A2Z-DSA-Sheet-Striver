int threeSum(int a[], int n, int X)
{
    int ThreeSum, min = INT_MAX, low, high, sum = 0;
    sort(a, a + n);
    for (int i = 0; i < n; i++)
    {
        low = i + 1, high = n - 1;
        while (low < high)
        {
            sum = a[i] + a[low] + a[high];
            if (abs(sum - X) < min)
            {
                min = abs(sum - X);
                ThreeSum = sum;
            }
            if (sum < X)
                low++;
            else
                high--;
        }
    }
    return ThreeSum;
}