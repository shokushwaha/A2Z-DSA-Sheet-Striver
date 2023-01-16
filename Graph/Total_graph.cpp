long long count(int n)
{
    int x = n * (n - 1) / 2;
    long long ans = pow(2, x);
    return ans;
}