int setBit(int n)
{
    int x = n, z = log2(n) + 1;

    for (int i = 0; i < z; i++)
    {
        x = (x | (1 << i));
        if (x != n)
            break;
    }

    return x;
}