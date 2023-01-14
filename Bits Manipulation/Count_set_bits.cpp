int count(int n)
{
    int mask = 1;
    int cnt = 0;
    while (n)
    {
        if (mask & n == 1)
            cnt++;
        n = n >> 1;
    }
    return cnt;
}