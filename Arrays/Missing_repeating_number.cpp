int missingNumber(int A[], int N)
{
    // Your code goes here
    int sum = N * (N + 1) / 2;
    for (int i = 0; i < N - 1; i++)
    {
        sum -= A[i];
    }
    return sum;
}
int repeatingNumber(int A[], int N)
{
    int temp = 0;
    int sum = N * (N + 1) / 2;
    for (int i = 0; i < N - 1; i++)
    {
        temp = temp + sum - A[i];
    }
    return abs(temp);
}