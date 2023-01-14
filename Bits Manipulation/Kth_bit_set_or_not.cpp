bool check(int n, int k)
{
    int mask = 1 << k;

    if (mask & n)
        return true;
    else
        return false;
}